#include <stdio.h>

void main()
{
	short x = -1;
	unsigned int y = -1;

	printf("x:%x, y:%x\n", x, y);

	for (int i =0; i< 64; i++) {

		printf("%d bit:%x\n", i, (x&(1 << i))>>i);
	}

	printf("%d\n", 1 << 31);
}
