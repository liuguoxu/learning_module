#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char * FILE_NAME = "./testfile";

void main()
{
	int ret = access(FILE_NAME, R_OK);
	
	if(ret == 0){
		printf("file exists\n");
		FILE *fp = fopen(FILE_NAME, "r");
		if(!fp){
			printf("fopen failed\n");
			return;
		}
		char *line = NULL;
		size_t sz = 0;
		size_t sz_ret = getline(&line, &sz, fp);
		if(sz_ret == -1)
			printf("getline error\n");
		else
			printf("sz_ret:%ld, sz:%ld, line:%s\n", sz_ret, sz, line);

		free(line);
		pclose(fp);
	}else{
		printf("file not exists\n");
	}
}

