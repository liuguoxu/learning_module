#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	const char *file_name = "/home/jere/workspace/learning_module/c_/popen/start.sh";

	char opt[128] = {0};
	char *argv[3] = {(char *)file_name, opt, NULL};

	char *start = "start \"jack\" \"peter\" tom";
	sprintf(opt, "%s", start);

	pid_t pid = fork();

	if(pid == 0) {
		for (int i = STDERR_FILENO + 1; i < getdtablesize(); ++i) {
			close(i);
		}

		if (execv(file_name, argv) != 0) {
			printf("execv error!\n");
			return;
		}

		exit(0);
	} else if (pid > 0 ){
		int st = 0;
		if (waitpid(pid, &st, 0) == -1) {
			printf("waitpid error!\n");
			return;
		}

		if (!WIFEXITED(st)) {
			printf("WIFEXITED error!\n");
			return;
		}
	}

	printf("end~\n");


}
