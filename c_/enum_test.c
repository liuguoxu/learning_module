#include <stdio.h>

typedef enum {
	F = 0,
	S = 1,
	MAX
}E_T;

void main()
{
	E_T t;

	t = MAX;

	printf("max:%d\n", t);
}
