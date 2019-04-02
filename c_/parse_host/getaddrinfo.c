#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <strings.h>
void main()
{
	char *host = "www.baidu.com";

	int ret = 0;

	struct addrinfo hints;
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	struct addrinfo *res, *servaddrs;

	ret = getaddrinfo(host, "80", &hints, &res);

	if (ret != 0) {
		printf("getaddrinfo error!\n");
		return;
	}
	printf("getaddrinfo succ\n");

	for (servaddrs = res; servaddrs != NULL; servaddrs = servaddrs->ai_next) {
		struct sockaddr_in *in = (struct sockaddr_in *)servaddrs;
		printf("addr:%s\n", inet_ntoa(in->sin_addr));
	}
}
