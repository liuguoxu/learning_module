#include <unistd.h>
#include <stdio.h>
#include <string.h>

//管道的用法2
//兄弟子进程之间进行通信
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

	//创建两个子进程
	for(int i = 0;i < 2; i++) {
		//子进程中直接break，父进程继续循环
		if(fork() == 0)
			break;
	}

	if(i == 0) {//first child, write
		close(fds[0]);
		char *p = "a text write to pipe~";
		write(fds[1], p, strlen(p));
		printf("write to pipe success~\n");
		close(fds[1]);
	}else if(i == 1) {//second chile, read
		close(fds[1]);
		char buf[1024] = "";
		read(fds[0], buf, sizeof(buf));
		printf("read from pipe:%s\n", buf);

		close(fds[0]);
	}else {//father
		close(fds[0]);
		close(fds[1]);
		printf("wait for my children~\n");
	
		for(int i = 0; i <= ; i++)
			wait();
	}

	
}
