#include "channel.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>

using std::string;

class AwesomeServer {
public:
	AwesomeServer(EventLoop& loop, string ip = "127.0.0.1", uint16_t port = 54321): loop_(loop) {
		//create socket
		fd_ = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
		if (fd_ == -1) {
			std::cout << "socket error" << std::endl;
			exit(-1);
		}

		struct sockaddr_in sa;
		if (inet_pton(AF_INET, ip.c_str(), &sa.sin_addr) != 1) {
			std::cout << "acceptor failed to inet_ation with ip: " << ip << std::endl;
			exit(-1);
		}
		sa.sin_family = AF_INET;
		sa.sin_port = htons(port);

		if (-1 == ::bind(fd_, (const struct sockaddr *)&sa, sizeof(sa))) {
			std::cout << "acceptor bind error" << std::endl;
			exit(-1);
		}

		if (::listen(fd_, 10)) {
			std::cout << "acceptor failed to listen socket" << std::endl;
			exit(-1);
		}
		std::cout << "server listen at port: " << port << std::endl;

		chn_ = new Channel(loop_, fd_);
		chn_->setReadCallBack(std::bind(&AwesomeServer::msgComing, this));
		chn_->enableReading();
	}


	~AwesomeServer() {
		std::cout << "~AwesomeServer destructor" << std::endl;
		close(fd_);
	}

private:
	void msgComing() {
		std::cout << "i got a message~" << std::endl;
	}

private:
	EventLoop& loop_;
	Channel* chn_;
	int fd_;
};
