#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int age;
	char name[100];
}static *g_node;

void main()
{
	g_node = malloc(sizeof(struct node));
	g_node->age = 12;
	strcpy(g_node->name, "good~");

	printf("%s:%d\n", g_node->name, g_node->age);

	free(g_node);
}
