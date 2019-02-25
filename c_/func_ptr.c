#include <stdio.h>


static void (* func)(int);

void func1(int a)
{
	printf("func1:%d\n", a);
}

void func2(int a)
{
	printf("func2:%d\n", a);
}

void main()
{
	func = func1;
	func(123);

	func = func2;
	func(456);
}
