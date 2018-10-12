#include <stdio.h>
#include <unistd.h>
void main()
{
	char *cmd = "./start.sh";

	if(!popen(cmd, "r")) {
		printf("popen failed!\n");
		return;
	}

	while(1) {
		sleep(1);
	}
}
