#include <stdio.h>
//#include <math.h>
#include <time.h>
#include <stdlib.h>

void main()
{
	time_t time_now = time(NULL);
	srand((unsigned int)time_now);

	printf("%d\n", rand());
	
	int a = rand()%1000;
	printf("a %03d\n", a);
}
