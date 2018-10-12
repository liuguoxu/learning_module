//判断系统是大端还是小端
#include <stdio.h>


//1 - big endian
//0 - small endian
int big_or_small()
{
	int x = 0x12345678;

	return (*((char *)&x) == 0x12) ? 1:0;
}

void main()
{
	printf("endian:%d\n", big_or_small());
}
