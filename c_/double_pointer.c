//
// Created by jere on 2019-3-28.
//
#include <stdio.h>


void test(char **p)
{
    printf("%s\n", p[0]);
}


int main()
{
    char str[4][20] = {"hello", "world", "ya", "le"};

    test(str)
}