//
// Created by jere on 2019-3-12.
//
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

void signal_handle1(int sig_num)
{
    printf("pid2 got sig:%d\n", sig_num);
}

void *func1()
{
    signal(SIGABRT, signal_handle1);

    while (1) {
        sleep(1);
    }
}

void signal_handle2(int sig_num)
{
    printf("pid1 got sig:%d\n", sig_num);
}

void *func2()
{
    signal(SIGABRT, signal_handle2);

    while (1) {
        sleep(1);
    }
}

void pthread_test(pthread_t pid)
{
    int pthread_kill_err;
    pthread_kill_err = pthread_kill(pid, 0);

    if (pthread_kill_err == ESRCH)
        printf("pid:0x%x has exited\n", (unsigned int)pid);
    else if (pthread_kill_err == EINVAL)
        printf("pid:0x%0x is invalid/n", (unsigned int)pid);
    else
        printf("pid:0x%x is still alive\n", (unsigned int)pid);
}

int main()
{
    pthread_t pid1;
    if (pthread_create(&pid1, NULL, func1, NULL) != 0) {
        exit(-1);
    }

    pthread_test(pid1);

    pthread_t pid2;
    if (pthread_create(&pid2, NULL, func2, NULL) != 0) {
        exit(-1);
    }

    pthread_test(pid2);

    pthread_kill(pid1, SIGABRT);
    pthread_kill(pid2, SIGABRT);

    sleep(1);

    return 0;
}

