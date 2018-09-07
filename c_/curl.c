#include <stdio.h>

void main()
{
	char cmd[128] = "curl ftp://dev.ikuai8.com:21/审计171/ctrl_alarm_rules.sha2 -u ikftp:ikftp@Ftp!";

	FILE *fp = popen(cmd, "r");
	if(!fp) {
		printf("popen error!\n");
		return;
	}

	char buf[128];
	fread(buf, 128, 1, fp);
	printf("buf:%s\n", buf);

	pclose(fp);
}
