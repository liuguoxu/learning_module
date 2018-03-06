#include <stdio.h>

#define JSTX_IND      JSTX"_indx"
#define	JSTX			"003"
void main()
{
//	int a = JSTX;
	char str[16] = JSTX_IND;
//	printf("%03d\n",a);
	printf("%s\n", str);
}
