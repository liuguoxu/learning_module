#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <time.h>

void main()
{
	pid_t pid = fork();

	if (pid == 0) {
		printf("i am child, my ppid is %d\n", getppid());

		printf("STDERR_FILENO:%d, dtablesize:%d\n", STDERR_FILENO, getdtablesize());

		for (;;){
			sleep(1);
		}

	} else {
		printf("i am father, my child's pid is %d\n", pid);

		int st = 0;
		waitpid(pid, &st, 0);

		sleep(1);
		printf("child out ~st:%d\n", st);

		if (!WIFEXITED(st)) {
			printf("child exited abnormal~\n");
		} else {
			printf("exit status :%u\n", WEXITSTATUS(st));
		}
	}

}
