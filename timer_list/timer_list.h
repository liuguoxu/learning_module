#include <time.h>


#define TIMER_NAME_LEN	32

typedef void(* plug_timer_cb)(void *);

typedef struct _plug_timer
{
	char name[TIMER_NAME_LEN+1];
	time_t expire;			//next event time
	int period;				//event period
	plug_timer_cb callback;
	void *data;				//callback parameter
	struct _plug_timer *next;
}plug_timer_t,*plug_timer_p;



void init_timer_list();
void destroy_timer_list();
int update_timer(char *name, time_t expire);

void add_timer(char *name,time_t expire, int period, plug_timer_cb callback,void *data);
int tick();



