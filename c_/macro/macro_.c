//宏定义测试
#include <stdio.h>


#define ADD(a, b) a + b

#define COMBINE(x, y) x y


#define FOO_ 0
#define FOO_1 1
#define PRIMITIVE_CAT(x, y) x y


void main()
{
	int x = ADD(1,2);

	printf("%d\n", x);

//	printf("%s\n", COMBINE("a", 9));

	char *ret = PRIMITIVE_CAT(FOO_, 1)
	printf("%s\n", ret);
}
