#include <stdio.h>

struct S {
	int a: 1;
	int b: 2;
};

void main()
{
	struct S s;
	printf("%d,%d\n", s.a, s.b);
}
