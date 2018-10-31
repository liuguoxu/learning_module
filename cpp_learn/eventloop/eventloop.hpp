#ifndef IK_DATA_CAPTURE_EVENTLOOP_H_
#define IK_DATA_CAPTURE_EVENTLOOP_H_

#include "poll.hpp"

#include <vector>
#include <functional>
#include <map>
#include <memory>
#include <mutex>

class Channel;

using cppbase::EventPoll;
using std::shared_ptr;

class EventLoop {
public:
	typedef std::function<void()> Functor;
	typedef shared_ptr<Channel> ChannelPtr;

public:
	EventLoop();
	~EventLoop();

	void loop();
	void stop();

	void runInLoop(Functor cb);
	void runAfter(int sec, Functor cb);
	void runEvery(int sec, Functor cb);

	void enableWriting(ChannelPtr chnl);
	void enableReading(ChannelPtr chnl);
	void removeChnl(ChannelPtr chnl);

private:
	EventPoll poll_;
	bool looping_;
	std::mutex mtx_;
	std::vector<Functor> pendings_;
	std::map<int, ChannelPtr> chnls_;
};

#endif
