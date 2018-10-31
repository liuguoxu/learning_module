#ifndef IK_DATA_CAPTURE_CHANNEL_H_
#define IK_DATA_CAPTURE_CHANNEL_H_

#include "eventloop.hpp"
#include <iostream>
#include <memory>
#include <functional>

using std::shared_ptr;

class Channel : public std::enable_shared_from_this<Channel> {
public:
	typedef std::function<void()> EventCallBack;

public:
	Channel(EventLoop& loop, int fd)
		: loop_(loop)
		, event_flag_(0)
		, fd_(fd)
	{
		std::cout << "create fd" << std::endl;
	}

	~Channel()
	{
		std::cout << "channel destruct" << std::endl;
		close(fd_);
	}

	void setReadCallBack(EventCallBack cb)
	{  read_cb_ = cb; }

	void setWriteCallBack(EventCallBack cb)
	{  write_cb_ = cb; }

	void enableWriting()
	{
		loop_.enableWriting(shared_from_this());
		event_flag_ |= 2;
	}

	void enableReading()
	{
		loop_.enableReading(shared_from_this());
		event_flag_ |= 1;
	}

	void handleWrite()
	{
		if (write_cb_) {
			write_cb_();
		}
	}

	void handleRead()
	{
		if (read_cb_) {
			read_cb_();
		}
	}

	void remove()
	{
		loop_.removeChnl(shared_from_this());
	}

	int getfd()
	{  return fd_; }

	bool eventEmpty()
	{  return !event_flag_; }

private:
	EventLoop& loop_;
	EventCallBack read_cb_;
	EventCallBack write_cb_;
	uint8_t event_flag_;
	int fd_;
};

#endif

