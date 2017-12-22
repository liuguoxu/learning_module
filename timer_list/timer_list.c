#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timer_list.h"

#define NO_TIMER 	60*5
static plug_timer_p g_timer_list = NULL;

/*
add new timer to list
*/
static void insert_timer_into_list(plug_timer_p timer)
{
	if(!timer)
	{
		printf("timer is NULL\n");
		return;
	}

	if(timer->period == 0)
	{
		printf("timer period is 0\n");
		return;
	}
	if(!g_timer_list)
	{
		g_timer_list = timer;
		g_timer_list->next = NULL;
		return;
	}
	if(timer->expire < g_timer_list->expire)
	{
		timer->next = g_timer_list;
		g_timer_list = timer;
		return;
	}
	plug_timer_p tmp_prev = g_timer_list;
	plug_timer_p tmp = tmp_prev->next;
	while(tmp)
	{
		if(timer->expire < tmp->expire)
		{
			timer->next = tmp;
			tmp_prev->next = timer;
			return;
		}
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	tmp_prev->next = timer;
	timer->next =NULL;
}

/*
create a new timer and add to list
*/
void add_timer(char *name,time_t expire, int period, plug_timer_cb callback,void *data)
{
	if(!callback)
	{
		printf("timer callback is NULL!\n");
		return;
	}

	if(0 == period)
	{
		printf("timer period is 0\n");
		return;
	}

	plug_timer_p timer = (plug_timer_p)malloc(sizeof(plug_timer_t));
	memset(timer, 0 ,sizeof(plug_timer_t));
	strncpy(timer->name , name, TIMER_NAME_LEN+1);
	timer->expire = expire;
	timer->period = period;
	timer->callback = callback;
	timer->data = data;

	printf("timer_name = %s\n", timer->name);
	insert_timer_into_list(timer);
}

/*
remove a timer from list
ret:0  success, -1 fail
*/
int remove_timer(char *name)
{
	if(!g_timer_list)
	{
		printf("timer list is empty!\n");
		return -1;
	}
	
	plug_timer_p tmp = g_timer_list;
	if(!strcmp(tmp->name , name))
	{
		g_timer_list = tmp->next;
		free(tmp);
		return 0;
	}

	plug_timer_p tmp_prev = g_timer_list;
	tmp = tmp->next;
	while(tmp)
	{
		if(!strcmp(tmp->name , name))
		{
			tmp_prev->next = tmp->next;
			free(tmp);
			return 0;
		}
		tmp_prev = tmp;
		tmp = tmp->next;
	}

	printf("timer not in list, name=%s\n",name);
	return -1;

}

/*
take out timer from list, BUT NOT FREE NODE !
*/
static void takeout_timer_from_list(plug_timer_p timer)
{
	if(timer == g_timer_list)
	{
		g_timer_list = timer->next;
		return;
	}

	plug_timer_p tmp= g_timer_list->next;
	plug_timer_p tmp_prev = g_timer_list;

	while(tmp)
	{
		if(timer == tmp)
		{
			tmp_prev->next = tmp->next;
			break;
		}
		tmp_prev = tmp;
		tmp = tmp->next;
	}
	
}

void destroy_timer_list()
{
	plug_timer_p tmp = g_timer_list;

	while(tmp)
	{
		plug_timer_p node = tmp->next;
		free(tmp);
		tmp = node;
	}
}

/*
change timer expire time
ret: 0  success, -1  error
*/
int update_timer(char *name, time_t expire)
{
	plug_timer_p tmp = g_timer_list;
	while(tmp)
	{
		if(!strcmp(tmp->name , name))
		{
			takeout_timer_from_list(tmp);
			tmp->expire = expire;
			insert_timer_into_list(tmp);
			return 0;
		}
		tmp = tmp->next;
	}
	return -1;
}
int tick()
{
	if(!g_timer_list)
		return NO_TIMER;

	time_t cur = time(NULL);
	plug_timer_p tmp = g_timer_list;

	while(tmp->expire <= cur)
	{
		//printf("callback timer =%s\n", tmp->name);
		tmp->callback(tmp->data);

		takeout_timer_from_list(tmp);
		/*update expire time*/
		tmp->expire += tmp->period;
		insert_timer_into_list(tmp);
		tmp = g_timer_list;
	}
	return(g_timer_list->expire - cur);
}
