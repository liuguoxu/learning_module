//数组指针测试
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
char (*g_p)[20] = NULL;

void test_func(char (**p)[20])
{
	*p = (char (*)[20])calloc(5, sizeof(char [20]));
	strcpy((*p)[0], "aaaa");
	strcpy((*p)[1], "xaa");
}

int main()
{
	test_func(&g_p);

	printf("g_p0 = %s,g_p1 = %s\n", g_p[0], g_p[1]);

	free(g_p);
	return 0;
}
