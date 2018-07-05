#include <stdio.h>

typedef enum{
	AP_USE_CLOSE = 0,
	AP_USE_AUDIT,
	AP_USE_PROBE,
	AP_USE_BOTH
}AP_USE;


void main()
{
	AP_USE x;
	x = AP_USE_BOTH;
	printf("x= %d\n",AP_USE_AUDIT);
}
