#include <stdio.h>
#include <stdlib.h>

void main()
{
	char *filename = "testfile";
	FILE *fp = fopen(filename, "r");

	char *line = NULL;
	size_t sz = 0;

	while(getline((char **)&line, &sz, fp) != -1) {
		printf("%s\n", line);
	}

	free(line);
	fclose(fp);
}
