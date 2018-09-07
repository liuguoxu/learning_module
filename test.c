#include <stdio.h>
#include <time.h>
char *file = "a.txt";

void main()
{
	time_t t = 1535512062;
	struct tm *lt;

	lt = localtime(&t);

	char now[128];
	strftime(now, 128, "%Y-%m-%d %H:%M:%S", lt);
	printf("%s\n", now);
}

