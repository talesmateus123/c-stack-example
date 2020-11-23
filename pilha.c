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
void show(stack *p);
void clean(stack *p);
bool isSorted(stack *p);

int main() {
	stack *p;
	p=create();
	printf("%p\n", p->top);
	push(p, 3);
	push(p, 2);
	push(p, 1);
	show(p);
	printf("------------------------------\n");
	printf("%d\n", isSorted(p));
	printf("------------------------------\n");
	clean(p);
	
	show(p);
	/*
	printf("%d\n", pop(p));
	printf("%d\n", pop(p));
	printf("%d\n", p->top->num);
	printf("%d\n", pop(p));
	printf("%d\n", isEmpty(p));
	*/
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

void show(stack *p) {
	no *aux;
	if(isEmpty(p))
		printf("Pilha vazia\n");
	else {
		aux = p->top;
		while(aux!=NULL) {
			printf("%d\n", aux->num);
			aux = aux->prox;
		}
	}
}

void clean(stack *p) {
	int num;
	while(!isEmpty(p)) {
		num=pop(p);
	}
}

bool isSorted(stack *p) {
	int aux, num;
	if(isEmpty(p)) {
		printf("Pilha vazia\n");
		return 0;
	}
	num = pop(p);
	while(!isEmpty(p)) {
		aux = pop(p);
		if(num > aux) {
			return 0;
		}
	}
	return 1;

}