#include <stdio.h>
#include "hello.h"
#include "cJSON.h"
void main()
{
	char *file = "test.txt";

	FILE *fp = fopen(file, "r");

	if(!fp) {
		printf("fopen error\n");
		return;
	}

	char buf[1024] = "";
	fread(buf, 1024 , 1, fp);

	printf("buf:%s\n", buf);

	fclose(fp);

	cJSON *root = cJSON_Parse(buf);
	if(!root) {
		printf("cJSON_Parse error!\n");
		return;
	}

	printf("json:%s\n", cJSON_PrintUnformatted(root));

	cJSON_Delete(root);
	//hello();
}
