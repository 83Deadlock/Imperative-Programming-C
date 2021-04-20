#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void SinitStack (SStack s){	
	s->sp = -1;
}

int SisEmpty (SStack s){
	int r = 0;
	if(s->sp == -1) r = 1;
	return r;
}

int Spush (SStack s, int x){
	int r = 0;
	if(s->sp + 1 == Max) r = 1;
	else{
		s->values[++s->sp] = x;
	}
	return r;
}

int Spop (SStack s, int *x){
	int r = 0;
	if(SisEmpty(s)) r = 1;
	else {
		*x = s->values[s->sp--];
	}
	return r;
}
int Stop (SStack s, int *x){
	int r = 0;
	if(SisEmpty(s)) r = 1;
	else {
		*x = s->values[s->sp];
	}
	return r;
}

void ShowSStack (SStack s){
	printf("---Stack s---\n");
	printf("sp -> %d\n",s->sp);
	printf("valores -> ");
	for(int i = 0; i < s->sp; i++){
		printf("%d, ",s->values[i]);
	}
	printf("%d.\n---FINAL---\n",s->values[Max-1]);
}

int doubleSize(DStack s){
	int r = 0;
	s->size *= 2;
	s->values = realloc(s->values,s->size);
	if(s->values == NULL) r = 1;
	return r;
}

int halfSize(DStack s){
	int r = 0;
	s->size /= 2;
	s->values = realloc(s->values,s->size);
	if(s->values == NULL) r = 1;
	return r;
}

void DinitStack (DStack s){
	s = (struct dinStack*) malloc(sizeof(struct dinStack));
	s->size = 1;
	s->sp = -1;
	s->values = malloc(sizeof(int));
}

int DisEmpty (DStack s){
	return (s->sp == -1);
}

int Dpush (DStack s, int x){
	int r = 0;
	if(s->sp == (s->size - 1)) {
		if(doubleSize(s) != 0) r = 1;
	} else {
		s->values[++s->sp] = x;
	}
	return r;
}

int Dpop (DStack s, int *x){
	int r = 0;
	if(DisEmpty(s)) {
		if(halfSize(s) != 0) r = 1;
	}
	else {
		*x = s->values[s->sp--];
	}
	return r;
}

int Dtop (DStack s, int *x){
	int r = 0;
	if(DisEmpty(s)) r = 1;
	else{
		*x = s->values[s->sp];
	}
	return r;
}

void ShowDStack (DStack s){
	printf("---Stack s---\n");
	printf("size -> %d\n",s->size);
	printf("sp -> %d\n",s->sp);
	printf("valores -> ");
	for(int i = 0; i < s->sp; i++){
		printf("%d, ",s->values[i]);
	}
	printf("%d.\n---FINAL---\n",s->values[Max-1]);
}