#include<stdio.h>
#include<stdlib.h>

typedef struct n {
	int num;
	struct n *prox;
} no;

typedef struct t {
	no *top;
} stack;

stack * create();

int main() {
	stack *p;
	p=create();
	printf("%p\n", p->top);
	return 0;
}

stack * create() {
	stack *p = malloc(sizeof(stack));
	p->top=NULL;
	return p;
}