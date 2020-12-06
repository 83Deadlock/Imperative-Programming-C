#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
	int valor;
	struct slist * prox;
} Nodo, *LInt;

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

LInt init (LInt l){
	LInt t = l;
	LInt ant = malloc(sizeof(struct slist));
	ant->valor = 0;
	ant->prox = l;

	while(l->prox != NULL){
		ant = ant->prox;
		l = l->prox;
	}

	free(l);
	ant->prox = NULL;

	return t;
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

LInt concat (LInt a, LInt b){
	LInt new = a;
	while(a->prox != NULL){
		a = a->prox;
	}

	a->prox = b;
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

void main () {
	LInt l1,l2,l3;
	l1=l2=l3=NULL;
	printLInt(l1);

	l1 = cons(l1,0);	//Testing cons function
	puts("cons(0)");
	l1 = cons(l1,1);	
	puts("cons(1)");
	l1 = cons(l1,2);
	puts("cons(2)");
	printLInt(l1);		//Visualize result

	l1 = tail(l1);
	puts("tail");
	printLInt(l1);

	l1 = cons(l1,1);
	puts("cons(3)");
	printLInt(l1);

	l1 = init(l1);
	puts("init");
	printLInt(l1);

	l1 = init(l1);
	puts("init");
	printLInt(l1);

	l1 = snoc(l1,2);
	l1 = snoc(l1,3);
	puts("snoc");
	printLInt(l1);

	l2 = cons(l2,9);
	l2 = cons(l2,8);
	l2 = cons(l2,7);
	l3 = cons(l3,6);
	l3 = cons(l3,5);
	l3 = cons(l3,4);

	l3 = concat(l3,l2);
	l1 = concat(l1,l3);
	printLInt(l1);
}