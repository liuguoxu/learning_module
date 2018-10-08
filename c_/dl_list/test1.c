#include "list.h"
#include <stdio.h>
#include <string.h>

struct st_test {
    int A;
    char B[12];
};

void main()
{
    struct st_test ast;
    ast.A = 10;
	strcpy(ast.B, "abcd");
    printf("%ld\n", offsetof(struct st_test, B));

	printf("ast p:%p, ast.A p:%p, ast.B p:%p\n", &ast, &ast.A, ast.B);

	int *Ap = &ast.A;
	struct st_test *p = dl_list_entry(Ap, struct st_test, B);
	printf("p:%p\n", p);

	char *tmp = (char *)((char *)&ast + offsetof(struct st_test, B));
	printf("tmp:%s\n", tmp);

	//printf("C:%d\n", dl_list_entry(&ast, struct st_test, C));
}
