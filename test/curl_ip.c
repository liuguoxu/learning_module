#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	FILE *fp = popen("curl -s --connect-timeout 5 -k ip.cn", "r");

	if(!fp){
		printf("popen failed!\n");
		return;
	}

	char ret[64] = "";
	if(fgets(ret, 64, fp) == NULL) {
		printf("fgets failed!\n");
		fclose(fp);
		return;
	}

	printf("ret:%s\n", ret);

	char *saveptr = NULL;
	strtok_r(ret, "：", &saveptr);
//	strtok_r(NULL, "：", &saveptr);

	char ip[20] = "";
	strcpy(ip, strtok_r(NULL, "：", &saveptr));

	strcpy(ip, strtok_r(ip, " ", &saveptr));
	
	printf("ip:%s\n", ip);
	fclose(fp);

	return;
}
