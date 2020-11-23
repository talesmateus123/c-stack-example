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
void push(stack *p, int i);

int main() {
	stack *p;
	p=create();
	printf("%p\n", p->top);
	push(p, 1);
	printf("%d\n", p->top->num);
	return 0;
}

stack * create() {
	stack *p = malloc(sizeof(stack));
	p->top=NULL;
	return p;
}

void push(stack *p, int i) {
	no *aux;
	aux = malloc(sizeof(no));
	aux->num=i;
	aux->prox=p->top;
	p->top=aux;
}