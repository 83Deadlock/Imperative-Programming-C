#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
	char * palavra;
	int ocorr;
	struct celula * prox;
} * Palavras;

Palavras initPal(){
	Palavras p = malloc(sizeof(struct celula));
	p->ocorr = 0;
	p->prox = NULL;

	return p;
}

int isEmpty(Palavras p){
	int r = 0;
	if( p == NULL || p->ocorr == 0){
		r = 1;
	}
	return r;
}

int quantasP(Palavras p){
	Palavras aux = p;
	int count = 0;
	if(isEmpty(p));
	else{
		while(p!= NULL){
			count += p->ocorr;
			p = p->prox;
		}
	}
	p = aux;
	return count;
}

Palavras acrescenta(Palavras p, char* word){
	Palavras aux = p;


	if(isEmpty(p)){
		p->palavra = malloc(sizeof(char) * (strlen(word) + 1));
		strcpy(p->palavra,word);
		p->ocorr = 1;
	} else {
		Palavras ant = initPal();
		while(p->prox != NULL && strcmp(p->palavra,word) < 0){
			ant = p;
			p = p->prox;
		}

		if(strcmp(p->palavra,word) == 0){									//String igual
			p->ocorr = p->ocorr+1;

		} else if(strcmp(p->palavra,word) > 0){

			if(isEmpty(ant)){
				Palavras temp = malloc(sizeof(struct celula));
				temp->palavra = malloc(sizeof(char) * (strlen(word) + 1));
				strcpy(temp->palavra,word);
				temp->ocorr = 1;
				temp->prox = p;
				aux = temp;
			}

			Palavras temp = malloc(sizeof(struct celula));
			temp->palavra = malloc(sizeof(char) * (strlen(word) + 1));
			strcpy(temp->palavra,word);
			temp->ocorr = 1;
			temp->prox = p;
			ant->prox = temp;

		} else if(p->prox == NULL && strcmp(p->palavra,word) != 0){			
			Palavras temp = malloc(sizeof(struct celula));
			temp->palavra = malloc(sizeof(char) * (strlen(word) + 1));
			strcpy(temp->palavra,word);
			temp->ocorr = 1;
			temp->prox = NULL;
			p->prox = temp;

		} 
	}

	p = aux;
	return p;
}

Palavras acrescentaInicio(Palavras p, char* word){
	Palavras p1 = malloc(sizeof(struct celula));

	p1->palavra = malloc(sizeof(char)*(strlen(word)+1));
	strcpy(p1->palavra,word);
	p1->ocorr = 1;
	p1->prox = p;

	return p1;
}

Palavras acrescentaFim(Palavras p, char* word){
	Palavras p1 = p;

	while(p->prox != NULL){
		p = p->prox;
	}

	p->prox = malloc(sizeof(struct celula));
	p = p->prox;

	p->palavra = malloc(sizeof(char)*(strlen(word)+1));
	strcpy(p->palavra,word);
	p->ocorr = 1;
	p->prox = NULL;

	return p1;
}

void printPal(Palavras p){
	Palavras aux = p;
	while(p != NULL){
		printf("palavra = %s | ocorre = %d\n",p->palavra,p->ocorr);
		p = p->prox;
	}
	p = aux;
}

Palavras libertaLista(Palavras head){
	
   	Palavras tmp;

   	while (head != NULL){
       tmp = head;
       head = head->prox;

       free(tmp->palavra);
       free(tmp);
    }
    
    return NULL;
}

struct celula * maisFreq (Palavras p){
	Palavras aux = p;
	Palavras ret;
	int max = -1;

	if(isEmpty(p)){
		ret = NULL;
	} else{
		while(p != NULL){
			if(p->ocorr > max){
				max = p->ocorr;
				ret = initPal();
				ret->palavra = malloc(sizeof(char) * (strlen(p->palavra)+1));
				strcpy(ret->palavra,p->palavra);
				ret->ocorr = max;
			}
			p = p->prox;
		}
	}
	p = aux;
	return ret;
}

char* ultima (Palavras p){
	Palavras aux = p;
	char* ret;
	if(isEmpty(p)) ret = NULL;
	else{
		while(p->prox != NULL){
			p = p->prox;
		}
		ret = malloc(sizeof(char)*(strlen(p->palavra) + 1));
		strcpy(ret,p->palavra);
	}
	return ret;
}

void main(){

	Palavras palavras = initPal();

	if(isEmpty(palavras)){
		puts("Vazia");
	} else {
		puts("Não está vazia");
	}

	palavras = acrescenta(palavras,"gollum");
	palavras = acrescenta(palavras, "weezrd");
	palavras = acrescenta(palavras,"gollum");
	palavras = acrescenta(palavras,"frodo");
	palavras = acrescenta(palavras, "harry");

	printPal(palavras);

	struct celula* freq = maisFreq(palavras);

	if(freq != NULL) printf("A palavra mais frequente -> %s\n",freq->palavra);

	printf("A última palavra -> %s\n",ultima(palavras));

	palavras = libertaLista(palavras);

	if(isEmpty(palavras)){
		puts("Vazia");
	} else {
		puts("Não está vazia");
		printPal(palavras);
	}
	
}
