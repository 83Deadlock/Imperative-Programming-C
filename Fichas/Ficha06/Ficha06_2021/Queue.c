#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void SinitQueue (SQueue q){
	q->length = 0;
	q->front = -1;
}

int SisEmptyQ (SQueue q){
	return (q->length == 0);
}

int Senqueue (SQueue q, int x){
	int r = 0;
	if(q->length == Max) r = 1;
	else{
		if(SisEmptyQ(q)) q->front = 0;
		q->values[q->length++] = x;
	}
	return r;
}

int Sdequeue (SQueue q, int *x){
	int r = 0;
	if(SisEmptyQ(q)) r = 1;
	else{
		*x = q->values[q->front++];
		q->length--;
		if(SisEmptyQ(q)) q->front = -1;
	}
	return r;
}

int Sfront (SQueue q, int *x){
	int r = 0;
	if(SisEmptyQ(q)) r = 1;
	else{
		*x = q->values[q->front];
	}
}

void ShowSQueue (SQueue q){
	printf("---QUEUE---\n");
	printf("q->length = %d || q->front = %d\n",q->length,q->front);
	printf("q->values = ");
	for(int i = 0; i < (q->length - 1); i++){
		printf("%d, ",q->values[i]);
	}
	printf("%d.\n",q->values[q->length-1]);
	printf("---FINAL---\n");
}

int doubleSizeQ(DQueue q){
	int r = 0;
	q->size *= 2;
	q->values = realloc(q->values,q->size);
	if(q->values == NULL) r = 1;
	return r;
}

int halfSizeQ(DQueue q){
	int r = 0;
	q->size /= 2;
	q->values = realloc(q->values,q->size);
	if(q->values == NULL) r = 1;
	return r;
}

void DinitQueue (DQueue q){
	q = (struct dinQueue*) malloc(sizeof(struct dinQueue));
	q->size = 1;
	q->front = -1;
	q->length = 0;
	q->values = (int*) malloc(sizeof(int));
}

int DisEmptyQ (DQueue q){
	return (q->length == 0);
}

int Denqueue (DQueue q, int x){
	int r = 0;
	if(q->length == q->size){
		if(doubleSizeQ(q) != 0) r = 1;
	}

	if(q->front == -1){
		q->front = 0;
	}

	q->values[q->length] = x;
	q->length++;

	return r;
}

int Ddequeue (DQueue q, int *x){
	int r = 0;
	if(DisEmptyQ(q)){
		if(halfSizeQ(q) != 0) r = 1;
	} else {
		*x = q->values[(q->front)];
		q->length--;
		q->front++;
	}
	if(DisEmptyQ(q)){
		q->front = -1;
	}
	return r;
}

int Dfront (DQueue q, int *x){
	int r = 1;
	if(DisEmptyQ(q)) r = 0;
	else {
		*x = q->values[(q->front)];
	}
	return r;
}

void ShowDQueue (DQueue q){
	for(int i = 0; i < 5; i++) puts(" ");
	printf(" i | v \n");
	for(int k = 0; k < q->size; k++){
		printf(" %d | %d \n",k,q->values[k]);
	}
	printf("-------\n");
	printf("length = %d\n front = %d\n size = %d\n",q->length, q->front, q->size);
	printf("-------\n");
}