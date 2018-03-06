#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
	char name[1024] = "20150605093157706_123_440303_723005104_002.log";
	int str_len = strlen(name);
	char code[6];
	strncpy(code, name+str_len-7, 3);
	printf("%s\n",code);

	int code_i = atoi(code);
	printf("%d\n", code_i);
}
