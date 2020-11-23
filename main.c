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
void reverse(stack *p);
bool isEquals(stack *p1, stack *p2);

int main() {
	stack *p, *p2;
	p=create();
	p2=create();
	push(p, 3);
	push(p, 2);
	push(p, 1);
	push(p2, 3);
	push(p2, 2);
	push(p2, 1);
	printf("Normal p stack\n");
	printf("------------------------------\n");
	show(p);
	printf("Normal p2 stack\n");
	printf("------------------------------\n");
	show(p2);
	printf("Stacks isEquals\n");
	printf("------------------------------\n");
	printf("%d\n", isEquals(p, p2));
	printf("P1 stack reversed\n");
	printf("------------------------------\n");
	reverse(p);
	show(p);
	printf("Cleaned stack\n");
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

void reverse(stack *p) {
	stack *aux;
	aux = create();
	while(!isEmpty(p)) {
		push(aux, pop(p));

	}
	p->top=aux->top;
	aux->top=NULL;
	free(aux);
}

bool isEquals(stack *p1, stack *p2) {
	while(!isEmpty(p1) && !isEmpty(p2)) {
		if(pop(p1) != pop(p2)) {
			clean(p1);
			clean(p2);
			return false;
		}
	}
	if(!isEmpty(p1) || !isEmpty(p2)) {
		clean(p1);
		clean(p2);
		return false;
	}
	return true;
}