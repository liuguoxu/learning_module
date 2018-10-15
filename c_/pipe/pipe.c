#include <unistd.h>
#include <stdio.h>
#include <string.h>

//管道的用法
void main()
{
	int fds[2];
	pid_t pid;

	//fds[0] for read
	//fds[1] for write
	if(pipe(fds) == -1) {
		printf("pipe error!\n");
		return ;
	}

	pid = fork();

	if(pid < 0) {
		printf("fork error!\n");
		return;
	}

	//in child, close fds[1], only read
	if(pid == 0) {
		close(fds[1]);
		char buf[1024] = "";
		int len = read(fds[0], buf, sizeof(buf));
		printf("read %d bytes from pipe:%s\n", len, buf);
		close(fds[0]);
	}

	//in father, close fds[0], only write
	if(pid > 0) {
		close(fds[0]);
		char *p = "a text write to pipe~";
		write(fds[1], p, strlen(p));
		printf("write %d bytes to pipe\n", strlen(p));
		close(fds[1]);
	}
}
