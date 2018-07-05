#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
	char *list = NULL;
	list = calloc(1, 30*5);

	char ap1[30] = "aa:bb:cc(20,1);";
	char ap2[30] = "cc:cc:aa(333,0);";
	char ap3[30] = "pp:aa:aa(111,2);";

	strcat(list, ap1);
	strcat(list, ap2);
	strcat(list, ap3);

	list[strlen(list)-1] = '\0';

	printf("%s\n", list);
}
