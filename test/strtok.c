#include <stdio.h>
#include <string.h>

int main()
{
	char plug_main[128] = "libadtp_anhui-hefei-zhongxin.x86.so.0.0.6";

	char *new_name = strdup(plug_main);

	strtok(new_name, ".");
	printf("new_name = %s\n", new_name);
	printf("old name = %s\n", plug_main);

	char work_path[32];
	strcpy(work_path, new_name+8);

	printf("work_path = %s\n", work_path);
	printf("%p,,,%p\n", new_name, plug_main);
}
