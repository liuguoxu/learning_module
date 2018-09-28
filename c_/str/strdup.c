#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char s1[10] = "";
	printf("s1 len:%ld\n", strlen(s1));

	char *c = strdup(s1);

	printf("c:%s\n", c);

	printf("c len:%ld\n", strlen(c));
	free(c);
}
