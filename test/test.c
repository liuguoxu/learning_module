#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *get_mac()
{
	char (* out)[18] = calloc(5, 18);
	strcpy(out[0], "aaaaaaa");
	strcpy(out[1], "bbbbbbb");
	return (void *)out;
}

void main()
{
	char (* mac)[18];
	void * tmp = get_mac();
	mac = tmp;

	int size = sizeof(mac);
	printf("%s\n",mac[0]);
	printf("%s\n", mac[1]);
	free(mac);
}
