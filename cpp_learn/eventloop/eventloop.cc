#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "eventloop.hpp"
#include "channel.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::lock_guard;

EventLoop::EventLoop():looping_(false)
{
	if (!poll_.init()) {
		exit(EXIT_FAILURE);
	}
}

EventLoop::~EventLoop()
{}

void EventLoop::loop()
{
	looping_ = true;
	vector<EventPoll::EPEvent> ready_events;

	while (looping_) {
		int num_events = poll_.epoll_wait(ready_events, 1);
		if (num_events < 0) {
			cerr << "epoll error, " << strerror(errno) << endl;
			continue;
		}

		for (int i = 0; i < num_events; ++i) {
			auto iter = chnls_.find(ready_events[i].fd_);
			if (iter == chnls_.end()) {
				continue;
			}

			if (ready_events[i].events_ & EventPoll::EPOLL_EPOLLOUT) {
				iter->second->handleWrite();
			} else if (ready_events[i].events_ & EventPoll::EPOLL_EPOLLIN) {
				iter->second->handleRead();
			}
		}

		{
			lock_guard<std::mutex> guard(mtx_);
			for (size_t i = 0; i < pendings_.size(); ++i) {
				pendings_[i]();
			}
			pendings_.clear();
		}
	}
}

void EventLoop::stop()
{
	runInLoop(([&]() {
		looping_ = false;
	}));
}

void EventLoop::runInLoop(Functor cb)
{
	lock_guard<std::mutex> guard(mtx_);
	pendings_.push_back(cb);
}

void EventLoop::runAfter(int sec, Functor cb)
{}

void EventLoop::runEvery(int sec, Functor cb)
{}

void EventLoop::enableWriting(ChannelPtr chnl)
{
	if (chnl->eventEmpty()) {
		chnls_[chnl->getfd()] = chnl;
		poll_.epoll_add_fd(chnl->getfd(), EventPoll::EPOLL_EPOLLOUT);
	} else {
		poll_.epoll_modify_fd(chnl->getfd(), EventPoll::EPOLL_EPOLLOUT);
	}
}

void EventLoop::enableReading(ChannelPtr chnl)
{
	if (chnl->eventEmpty()) {
		chnls_[chnl->getfd()] = chnl;
		poll_.epoll_add_fd(chnl->getfd(), EventPoll::EPOLL_EPOLLIN);
	} else {
		poll_.epoll_modify_fd(chnl->getfd(), EventPoll::EPOLL_EPOLLIN);
	}
}

void EventLoop::removeChnl(ChannelPtr chnl)
{
	poll_.epoll_del_fd(chnl->getfd());
	chnls_.erase(chnl->getfd());
}

