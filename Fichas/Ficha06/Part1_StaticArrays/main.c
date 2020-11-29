#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct queue {
    int inicio, tamanho;
    int valores[MAX];
} QUEUE;

void initQueue (QUEUE *q){
    q->inicio = -1;
    q->tamanho = 0;
}

int isEmptyQ (QUEUE *q){
    return q->tamanho == 0;
}

int enqueue (QUEUE *q, int x){
    if(q->tamanho == MAX) return 1;
    else {
	if(isEmptyQ(q)){
		q->inicio = 0;
        }
        q->valores[q->tamanho] = x;
        q->tamanho++;
    }
    return 0;
}

int dequeue (QUEUE *q, int x){
    int r = 1;
    if(isEmptyQ(q)) r = 0;
    else{
    	*x = q->valores[q->inicio];
	q->tamanho--;
	q->inicio++;
    }
    if(isEmptyQ(q)){q->inicio = -1;}
    return r;
}

int front (QUEUE *q, int *x){
    int r = 1;
    if(isEmptyQ(q)) r = 0;
    else{
    	*x = q->valores[q->inicio];
    }
    return r;
}

void printQueue(QUEUE *q){
    int array;
    for(int k = 0; k < MAX; k++){
        array = q->valores[k];
        printf("valores[%d] = %d\n",k,array);
    }
    int t = q->tamanho;
    int i = q->inicio;
    printf("tamanho = %d\ninicio = %d\n",t,i);
}

void main() {
    QUEUE *q = malloc(sizeof(struct queue));
    initQueue(q);

    int vazia = isEmptyQ(QUEUE *q);
    printf("Devia ser 1 e é %d\n", vazia);

    enqueue(q,3);
    printQueue(q);

    enqueue(q,4);
    printQueue(q);

    int *x = malloc(sizeof(int));
    dequeue(q,x);
    printQueue(q);
    printf("x = %d\n", *x);

    front(q,x);
    printQueue(q);
    printf("x = %d\n",*x);
}
