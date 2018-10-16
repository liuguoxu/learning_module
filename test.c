#include <stdio.h>
#include <time.h>
char *file = "a.txt";

void main()
{
	char sh[128] = "abc";
	char opt[128] = "qwe";
	char * argv[3] = { (char*)sh, opt,  NULL};

	printf("argv0:%s, argv1:%s\n", argv[0], argv[1]);

	sprintf(argv[1], "%s", "zxcv");
	printf("argv0:%s, argv1:%s\n", argv[0], argv[1]);
}

