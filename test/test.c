#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PP "ppp"
void main()
{
	char *tmp = "1234";
//	printf("tmp = %s\n", tmp);
	printf(PP);
	char code[124];
	sprintf(code, "%s/""aaa"PP, tmp);
	printf("code = %s\n", code);
}
