/*popen读取程序推出状态和输出内容测试*/

#include <stdio.h>
#include <stdlib.h>

void doPopen(char *cmd)
{
	FILE *fp;
	if((fp = popen(cmd, "r")) == NULL) {
		printf("popen error!\n");
		return;
	}
	
	printf("before while\n");
	char buf[256] = "";
	while(fgets(buf, 255, fp) != NULL) {
		printf("buf =%s\n", buf);	
	}
	printf("after while\n");
	pclose(fp);
}

int doSystem(char *cmd)
{
	int ret;
	printf("before system\n");
	ret = system(cmd);
	printf("afer system,ret = %d\n", ret);
	return ret;
}

static char *str = "ping ww.baidu.c -c 3 > log.log";
static char *curl_cmd = "curl -a -v --ftp-create-dirs --connect-timeout 10 -m 20 -u ikftp:ikftp@Ftp! -T test.zip ftp://dev.ikuai8.com:21/东莞debug/test.zip.tmp -Q \"-RNFR test.zip.tmp\" -Q \"-RNTO test.zip\" 2>log.log";
void main()
{

	//doPopen(str);
	printf("curl_cmd: %s\n", curl_cmd);
	if(doSystem(curl_cmd) != 0) {
		rename("log.log", "tmp/log");
		printf("system failed! check log!\n");
	}
	return;
}
