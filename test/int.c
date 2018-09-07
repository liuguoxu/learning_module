#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(int *l, int len)
{
	int tmp[9] = {1,2,3,4,5,6,7,8,9};
	memcpy(l, tmp, len*sizeof(int));
}

void p_l(int *l, int len)
{
	int i = 0;

	for(; i < len; i++){
		printf("%d\n",l[i]);
	}
}


void main()
{
	int *l = (int *)calloc(10, sizeof(int));

	printf("%p\n", l);

	p_l(l, 10);
	func(l, 10);

	p_l(l, 10);

	
}
