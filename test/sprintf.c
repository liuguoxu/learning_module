#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
	char filename[50] = "12345.zip";
	char ok_file[50] = "";
		strcpy(ok_file, filename);
			ok_file[strlen(ok_file) - 3] = '\0';
				sprintf(ok_file, "%sok",ok_file);
	printf("%s\n", ok_file);
}
