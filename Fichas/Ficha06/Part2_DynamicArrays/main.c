#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	int size; // Guarda o tamanho do array valores
	int inicio, tamanho;                              
	int *valores;
} QUEUE;

void initQueue (QUEUE *q){
	q->inicio = -1;
	q->tamanho = 0;
	q->size = 1;
	q->valores = malloc(sizeof(int));
}

int isEmptyQ (QUEUE *q){
	return (q->tamanho == 0);
}

int enqueue (QUEUE *q, int x){
	if(q->tamanho == q->size){
		q->size *= 2;
		q->valores = realloc(q->valores,q->size);

		if(q->valores == NULL) return -1;
	}

	if(q->inicio == -1){
		q->inicio = 0;
	}

	q->valores[q->tamanho] = x;
	q->tamanho++;

	return 0;
}

int dequeue (QUEUE *q, int *x){
	int r = 1;
	if(isEmptyQ(q)) r = 0;
	else {
		*x = q->valores[(q->inicio)];
		q->tamanho--;
		q->inicio++;
	}
	if(isEmptyQ(q)){
		q->inicio = -1;
	}
	return r;
}

int front (QUEUE *q, int *x){
	int r = 1;
	if(isEmptyQ(q)) r = 0;
	else {
		*x = q->valores[(q->inicio)];
	}
	return r;
}

void printQueue(QUEUE *q){
	for(int i = 0; i < 5; i++) puts(" ");
	printf(" i | v \n");
	for(int k = 0; k < q->size; k++){
		printf(" %d | %d \n",k,q->valores[k]);
	}
	printf("-------\n");
	printf("tamanho = %d\n inicio = %d\n size = %d\n",q->tamanho, q->inicio, q->size);
	printf("-------\n");
}

void main(){
	QUEUE *q = malloc (sizeof(struct queue));
	initQueue(q);

	int vazia = isEmptyQ(q);
	printf("Devia ser 1 e é %d\n", vazia);

	enqueue(q,3);
	printQueue(q);

	enqueue(q,4);
	printQueue(q);

	int *x = malloc(sizeof(int));
	dequeue(q,x);
	printQueue(q);
	printf("x = %d\n",*x);

	front(q,x);
	printQueue(q);
	printf("x = %d\n",*x);
}