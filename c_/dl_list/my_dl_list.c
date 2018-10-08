#include "list.h"
#include <stdio.h>
#include <string.h>

typedef struct st_test {
    int A;
    char B[12];
    struct dl_list my_list;
} st_t;

struct dl_list g_list;

void main()
{
    st_t data1;
    data1.A = 1;
    strcpy(data1.B, "data1");

    st_t data2;
    data2.A = 2;
    strcpy(data2.B, "data2");

    dl_list_init(&g_list);

    dl_list_add(&g_list, &data1.my_list);
    dl_list_add(&g_list, &data2.my_list);

    st_t *tmp;
    dl_list_for_each(tmp, &g_list, st_t, my_list) {
        printf("A:%d, B:%s\n", tmp->A, tmp->B);
    }

    dl_list_del(&data1.my_list);

    dl_list_for_each(tmp, &g_list, st_t, my_list) {
        printf("A:%d, B:%s\n", tmp->A, tmp->B);
    }
}