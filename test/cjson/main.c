/*CJSON测试*/
#include "cJSON.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

cJSON *root;

void writeJSON()
{
	root = cJSON_CreateObject();
	cJSON *array = cJSON_CreateArray();

	cJSON_AddItemToObject(root, "INFO", array);
	cJSON *item = cJSON_CreateObject();

	cJSON_AddItemToArray(array, item);
	
	char name[128] = "nameaaajjjjjjjjjjjjjjjjjjjjjjsaaaaaaa";
	char v[128] = "abc213798264391826y8731268717493279";

	cJSON_AddStringToObject(item, name, v);

	char *tmp = cJSON_PrintUnformatted(root);
	free(tmp);

	cJSON_Delete(root);
	root = NULL;
//	fprintf(stdout, "%s\n", tmp);

}



void main()
{
	int i =0;
	for(i = 0;i <=1000000; i++) {
		writeJSON();
	}
	for(;;) {
		sleep(1);
	}
}

