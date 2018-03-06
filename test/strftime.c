#include <stdio.h>
#include <time.h>
#include <string.h>

void main()
{
	struct tm *timeinfo;

	time_t time_now = time(NULL);
	timeinfo = localtime(&time_now);

	char tt[100];
	strftime(tt, 80, "%Y%m%d/%H/", timeinfo);
	printf("%s\n", tt);
	
	char min_[6];
	strftime(min_, 10, "%M", timeinfo);
	printf("%s\n", min_);

	int min_i = atoi(min_);
	printf("%02d\n", min_i);

	int min_rpt = min_i/5*5 ;
	printf("%02d\n", min_rpt);

	char time_rpt[100];
	sprintf(time_rpt, "%s%d", tt, min_rpt);

	printf("time finally is %s\n", time_rpt);
}
