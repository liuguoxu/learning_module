#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a = calloc(1, sizeof(int));
	*a = 5;
	int *b = calloc(1, sizeof(int));

	*b = (*a)++;
	
	printf("*a=%d,*b=%d\n",*a,*b);
	return 1;
}
