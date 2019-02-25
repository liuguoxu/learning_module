#include <stdio.h>
#include <string.h>

struct st {
	char A[12];
	char B[12];
};


void assign(char *n, char *v)
{
	strcpy(n, v);
}

#define ASSIGN(st, v) do { \
	strcpy((st)->v, #v); \
	int a = 5; \
	printf("%d\n", a); \
} while(0)

void main()
{
	struct st mys;
	ASSIGN(&mys, A);
	ASSIGN(&mys, B);

	printf("%s, %s\n", mys.A, mys.B);
}
