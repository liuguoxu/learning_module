#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _ST{
	int a;
	char b[5];
	char c[7];
}*ST;

int main()
{
	ST s1 = (ST)calloc(1, sizeof(struct _ST));
	ST s2 = (ST)calloc(1, sizeof(struct _ST));

	s1->a = 123;
	strcpy(s1->b, "abc");
	strcpy(s1->c, "vbn");

	s2->a = 123;
	strcpy(s2->b, "abc");
	strcpy(s2->c, "vbn");

	int ret = memcmp(s1, s1, sizeof(struct _ST));
	printf("size = %ld,ret : %d\n",sizeof(struct _ST), ret);
	return 1;
}
