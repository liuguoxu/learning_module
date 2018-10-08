#include "list.h"
#include <stdio.h>

struct st_test {
    int A;
    char B[12];
};

void main()
{
    struct st_test ast;
    ast.A = 10;
    printf("%ld\n", offsetof(struct st_test*, A));
}