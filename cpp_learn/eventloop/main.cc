#include "main.hpp"
#include <time.h>

int main()
{
	EventLoop loop;
	AwesomeServer as(loop);

	while(1) {
		sleep(1);
	}
	return 0;
}
