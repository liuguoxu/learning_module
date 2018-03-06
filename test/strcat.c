#include <stdio.h>
#include <string.h>

void main()
{
	char dest[100] = "ss__";
	char src[100] = "abc";

	strcat(dest, src);
	printf("%s\n",dest);
}
