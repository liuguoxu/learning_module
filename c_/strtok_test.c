#include <stdio.h>
#include <string.h>

void main()
{
	char str[] = "B0-5A-DA-B4-72-72,b0-89-00-31-99-18";
	char *saveptr = NULL;

	char *p = strtok_r(str, ",", &saveptr);
	while(p) {
		printf("%s\n", p);
		p = strtok_r(NULL, ",", &saveptr);
	}
}

