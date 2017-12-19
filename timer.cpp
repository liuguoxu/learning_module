#ifndef LST_TIMER
#define LST_TIMER

#include <time.h>
#include <netinet/in.h>
#include <stdio.h>

#define BUFFER_SIZE 64

class util_timer;
//用户数据
struct client_data
{
    sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    util_timer* timer;
};
//定时器类:双向链表的结点
class util_timer
{
public:
    util_timer():prev(NULL),next(NULL){}
    //任务的设定时间
    time_t expire;
    //任务回调函数
    void (*cb_func)(client_data*);
    //回调函数处理的客户数据
    client_data* user_data;
    util_timer* prev;
    util_timer* next;
};
//定时器链表
class sort_time_lst
{
public:
    sort_time_lst():head(NULL),tail(NULL){}
    ~sort_time_lst()
    {
        util_timer* tmp = head;
        while(tmp)
        {
            head = tmp -> next;
            delete tmp;
            tmp = head;
        }
    }
    void add_timer(util_timer* timer)
    {
        if(!timer)
        {
            return;
        }
        if(!head)
        {
            head = tail = timer;
            return;
        }
        if(timer -> expire < head -> expire)
        {
            timer->next = head;
            head -> prev = timer;
            head = timer;
            return;
        }
        add_timer(timer,head);
    }
    //定时器的设定时间延长，向后调整
    void adjust_timer(util_timer* timer)
    {
        if(!timer)
        {
            return;
        }
        util_timer* tmp = timer -> next;
        if(!tmp || (timer -> expire < tmp -> expire))
        {
            return;
        }
        if(timer == head)
        {
            head = head->next;
            head->prev = NULL;
            timer->next = NULL;
            add_timer(timer,head);
        }
        else
        {
            timer->prev->next = timer->next;
            timer->next->prev = timer->prev;
            add_timer(timer,timer->next);
        }
    }
　　//删除定时器
    void del_timer(util_timer* timer)
    {
        if(!timer)
        {
            return;
        }
        if((timer == head)&&(timer == tail))
        {
            delete timer;
            head = NULL;
            tail = NULL;
            return;
        }
        if(timer == head)
        {
            head = head->next;
            head->prev = NULL;
            delete timer;
            return;
        }
        if(timer == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
            delete timer;
            return;
        }
        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        delete timer;
    }
    //SIGALRM信号每次被触发就在其信号处理函数中执行一次tick函数，来处理链表上到期的定时任务(调用到期的定时器的回调函数)，这个函数是核心
    void tick()
    {
        if(!head)
        {
            return;
        }
        printf("timer tick\n");
        time_t cur = time(NULL);
        util_timer* tmp = head;
        while(tmp)
        {
            if(cur < tmp->expire)
            {
                break;
            }
            tmp->cb_func(tmp->user_data);
            head = tmp->next;
            if(head)
            {
                head->prev = NULL;
            }
            delete tmp;
            tmp = head;
        }
    }

private:
    void add_timer(util_timer* timer,util_timer* lst_head)
    {
        util_timer* prev = lst_head;
        util_timer* tmp = prev->next;
        while(tmp)
        {
            if(timer->expire < tmp->expire)
            {
                prev->next = timer;
                timer->next = tmp;
                tmp->prev = timer;
                timer->prev = prev;
                break;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        if(!tmp)
        {
            prev->next = timer;
            timer->prev = prev;
            timer->next = NULL;
            tail = timer;
        }
    }

    util_timer* head;
    util_timer* tail;

};

#endif