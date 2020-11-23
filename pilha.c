#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct n {
	int num;
	struct n *prox;
} no;

typedef struct t {
	no *top;
} stack;

stack * create();
void push(stack *p, int i);
int pop(stack *p);
bool isEmpty(stack *p);

int main() {
	stack *p;
	p=create();
	printf("%p\n", p->top);
	push(p, 1);
	push(p, 2);
	push(p, 3);
	printf("%d\n", p->top->num);
	printf("%d\n", pop(p));
	printf("%d\n", pop(p));
	printf("%d\n", p->top->num);
	printf("%d\n", pop(p));
	printf("%d\n", isEmpty(p));
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

int pop(stack *p) {
	no *aux;
	int num;
	aux = p->top;
	p->top=p->top->prox;
	aux->prox=NULL;
	num=aux->num;
	free(aux);
	return num;
}

bool isEmpty(stack *p) {
	if(p->top == NULL)
		return true;
	return false;
}