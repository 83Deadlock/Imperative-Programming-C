#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slist{
	int valor;
	struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs){
	LInt r = malloc(sizeof(struct slist));
	if(r != NULL){
		r->valor = x;
		r->prox = xs;
	}
	return r;
}

LInt cons (LInt l, int x){
	LInt r = malloc(sizeof(struct slist)); //Alocating memory for the node we're adding to the slist

	r->valor = x; //Set the value to x
	r->prox = l;  //To set this node as the first of the list, we say the head of the list comes after this particular node

	return r;
}

LInt tail (LInt l){
	LInt t = l; 	//Create a temporary LInt to save the list's head's address

	l = l->prox;	
	free(t);

	return l;
}


LInt concat (LInt a, LInt b){
	LInt new = a;
	while(a->prox != NULL){
		a = a->prox;
	}

	a->prox = b;
	return new;
}

LInt snoc (LInt l, int x){
	LInt new = l;

	while(l->prox != NULL){
		l = l->prox;
	}

	l->prox = malloc(sizeof(struct slist));
	l = l->prox;
	l->valor = x;
	l->prox = NULL;

	return new;
}

void printLInt (LInt l){
	LInt aux = l;
	int i = 0;
	
	if(aux == NULL){puts("Empty List!\n");}
	else {
		printf("[Index|Value]\n");
		while(aux != NULL){
			printf("|  %d  |  %d  |\n",i,aux->valor);
			i++;
			aux = aux->prox;
		}
		printf("_____________\n");
	}
	for(int j = 0; j < 4; j++){
		printf("\n");
	}
}

typedef LInt Stack;

typedef struct {
	LInt inicio, fim;
} Queue;

Stack initStack(){
	return NULL;
}

int SisEmpty(Stack s){
	int r = 0;
	if(s == NULL){r=1;}
	return r;
}

int push(Stack *s, int x){
	int r = 0;
	*s = newLInt(x,*s);
	if(*s != NULL){
		r = 1;
	}
	return r;
}

int pop(Stack *s, int *x){
	int r = 1;
	if(*s == NULL) r = 0;
	else{
		*x = (*s)->valor;
		*s = (*s)->prox;
	}
	return r;
}

int top(Stack *s, int *x){
	int r = 1;
	if(*s == NULL) r = 0;
	else{
		*x = (*s)->valor;
	}
	return r;
}

Queue initQueue(){
	Queue q;
	q.inicio = NULL;
	q.fim = NULL;
	return q;
}

int QisEmpty(Queue q){
	int r = 0;
	if(q.inicio == NULL && q.fim == NULL) r = 1;
	return r;
}

int enqueue(Queue *q, int x){
	int r = 1;
	if(QisEmpty(*q)){
		(*q).inicio = newLInt(x,NULL);
		(*q).fim = (*q).inicio; 
		if(QisEmpty(*q)) r = 0;
	} else {
		(*q).fim->prox = newLInt(x,NULL);
		(*q).fim = (*q).fim->prox;
		if((*q).fim == NULL) r = 0;
	}
	return r;
}

int dequeue(Queue *q, int *x){
	int r = 1;
	if(QisEmpty(*q)){r = 0;printf("está vazia\n");} 
	else{
		*x = (*q).inicio->valor;
		if((*q).inicio == (*q).fim){
			*q = initQueue();
		} else (*q).inicio = (*q).inicio->prox;	
	}

	return r;
}

int front(Queue *q, int *x){
	int r = 1;
	if(QisEmpty(*q)) r = 0;
	else{
		*x = (*q).inicio->valor;
	}
	return r;
}

void printQueue(Queue q){
	Queue aux = q;
	while(aux.inicio != aux.fim){
		printf("valor = %d\n",aux.inicio->valor);
		aux.inicio = aux.inicio->prox;
	}
	printf("valor = %d\n",aux.inicio->valor);

}

void main(){

	//TESTES DAS STACKS
	/*
	//TESTE DO INIT
	Stack s = initStack();

	//TESTE DO ISEMPTY
	if(SisEmpty(s)) puts("1");
	else puts("0");

	//TESTES DO PUSH
	if(push(&s,3)) printf("valor apos push de 3 : %d\n",s->valor);
	else puts("0");
	if(push(&s,5)) printf("valor apos push de 5 : %d\n",s->valor);
	else puts("0");


	//TESTES DO TOP
	int topV;
	if(top(&s,&topV)) printf("topo da stack = %d\n",topV);
	else printf("Não tem elementos\n");

	//TESTES DO POP
	int x;
	if(pop(&s,&x)){ 
		if(SisEmpty(s)) printf("Esvaziou a stack\n");
		else printf("valor apos pop : %d\n",s->valor);
	}
	if(pop(&s,&x)){ 
		if(SisEmpty(s)) printf("Esvaziou a stack\n");
		else printf("valor apos pop : %d\n",s->valor);
	}
	if(pop(&s,&x)){ 
		if(SisEmpty(s)) printf("Esvaziou a stack\n");
		else printf("valor apos pop : %d\n",s->valor);
	}
	*/

	//TESTES DAS QUEUES
	//TESTE DO INIT
	Queue q = initQueue();
	
	if(QisEmpty(q)){
		puts("Está vazia");
	}

	if(enqueue(&q,3)) printf("valor apos enqueue de 3 : %d\n",q.inicio->valor);
	else puts("0");
	if(enqueue(&q,5)) printf("valor apos enqueue de 5 : %d\n",q.inicio->valor);
	else puts("0");

	//printQueue(q);

	//TESTES DO FRONT
	int frontV;
	front(&q,&frontV);
	printf("Front da QUEUE = %d\n",frontV);

	//TESTES DO POP
	int x;
	if(dequeue(&q,&x)){ 
		if(QisEmpty(q)) printf("Esvaziou a queue\n");
		else printf("valor apos dequeue : %d\n",q.inicio->valor);
	}
	if(dequeue(&q,&x)){ 
		if(QisEmpty(q)) {printf("Esvaziou a queue\n");}
		else printf("valor apos dequeue : %d\n",q.inicio->valor);
	}
	if(dequeue(&q,&x)){ 
		if(QisEmpty(q)) printf("Esvaziou a queue\n");
		else printf("valor apos dequeue : %d\n",q.inicio->valor);
	}

}