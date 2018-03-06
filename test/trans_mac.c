#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char mac[20] = "ac-nf-ke-fa-df-ak";
	char name[8] = "";

	strcpy(name, mac+9);
	printf("%s\n", name);

	int i, j;
	for(i=0,j=0;name[i] != '\0'; i++)
	{
		if(name[i] != '-')
		{
			name[j] = name[i];
			j++;
		}
	}
	name[j] = '\0';
	printf("%s\n", name);
}
