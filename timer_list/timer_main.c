#include <stdio.h>
#include <string.h>
#include "timer_list.h"

#define KOBE_24 "kobe_24"
#define KOBE_8	"kobe_8"
#define IVERSION_3  "iversion_3"

#define KOBE_24_PERIOD 24
#define KOBE_8_PERIOD  8
#define IVERSION_3_PERIOD  3

void kobe_24()
{
	printf("i am kobe 24\n");
}

void kobe_8()
{
	printf("i am kobe 8\n");
}

void iversion_3()
{
	printf("i am iversion_3\n");
}
void main()
{
	add_timer(KOBE_8, time(NULL), KOBE_8_PERIOD, &kobe_8, NULL);

	add_timer(KOBE_24, time(NULL), KOBE_24_PERIOD, &kobe_24, NULL);

	add_timer(IVERSION_3, time(NULL), IVERSION_3_PERIOD, &iversion_3, NULL);
	
	while(1)
	{
		int expire = tick();
		printf("sleep for %d seconds\n",expire);
		sleep(expire);
	}
}
