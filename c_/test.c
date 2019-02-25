#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int check(char *account)
{
	if(strlen(account) < 10)
        return -1;

    if(strncmp(account, "IK", 2) != 0 || account[10-1] != '_')
        return -1;

	return 0;
}

void main()
{
	if (2 >1 
		&& 1>2) {
		printf("da");
	}	
}
