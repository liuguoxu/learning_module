#include <stdio.h>
//#include <math.h>
#include <time.h>
#include <stdlib.h>

#define DEFAULT_SEED 9527

int createRand(int max)
{
	static unsigned int myseed = DEFAULT_SEED;
	printf("myseed is %d\n", myseed);
	
	srand(myseed);

	printf("%d\n", rand());
	
	myseed++;
	return rand()%max;
}

void main()
{
	int u = 20;
	while(u) {
		int x = createRand(1);
		printf("x:%d\n", x);
		u--;
	}
}
