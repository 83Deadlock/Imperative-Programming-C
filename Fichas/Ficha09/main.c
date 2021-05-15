#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d){
	ABin a = malloc(sizeof(struct nodo));
	if(a!=NULL){
		a->valor = r;
		a->esq = e;
		a->dir = d;
	}
	return a;
}

int altura (ABin a){
    int ret = 1;
    if (a != NULL) {
    	int e = 0;
    	int d = 0;
    	if(a->esq != NULL){
    		e = altura (a->esq);
    	}
    	if(a->dir != NULL){
    		d = altura (a-> dir);
    	}

        if ( e  > d )
            ret = 1 + e;
        else ret = 1 + d;
    } else {
    	ret = 0;
    }
    return ret;
}

int nFolhas (ABin a){
	int ret = -1;
	if (a == NULL) ret = 0;
	if (a->esq == NULL && a->dir == NULL) ret = 1;
	if (ret == -1){
		ret = nFolhas(a->esq)+nFolhas(a->dir);
	}
	return ret;
}


ABin maisEsquerda(ABin a){
	if (a != NULL){
		while (a->esq != NULL){
			a = a -> esq;
		}
	}
	 
	return a;
}

void imprimeNivel (ABin a, int l){
	if (a == NULL) return;
	if (l == 0) printf ("%d\n",a->valor);
	else{
		imprimeNivel(a->esq,l-1);
		imprimeNivel(a->dir,l-1);
	}
}

int procuraE (ABin a, int x){
	if (a == NULL) return 0;
	if (a->valor == x) return 1;
	return (procuraE(a->esq,x) || procuraE(a->dir,x));
}

struct nodo *procura (ABin a, int x){
	while (a != NULL && a->valor != x){
		if (a->valor > x) a = a->esq;
		else a = a -> dir;
	}
	return a;
}

int nivel (ABin a, int x){
	int alt=0;
	while (a != NULL && a->valor != x){
		if(a->valor > x) a = a->esq;
		else a = a->dir;
		alt++;
	}
	if (!a) alt = -1;
	return alt;
}

void imprimeAte (ABin a, int x){
	if (!a){
		if (x < a->valor) imprimeAte(a->esq,x);
		else if (x == a->valor){
			imprimeAte(a->esq,x);
			printf("%d\n",a->valor);
		}else {
			imprimeAte(a->esq,x);
			printf("%d\n",a->valor);
			imprimeAte(a->dir,x);
		}
	}
}

void main(){
	ABin um = newABin(1,NULL,NULL);
	ABin tres = newABin(3,NULL,NULL);
	ABin cinco = newABin(5,NULL,NULL);
	ABin sete = newABin(7,NULL,NULL);

	ABin dois = newABin(2,um,tres);
	ABin seis = newABin(6,cinco,sete);
	
	ABin quatro = newABin(4,dois,seis);

	printf("Numero de folhas = %d\n",nFolhas(quatro));
	printf("Altura da arvore = %d\n", altura(quatro));
	printf("Imprimir nivel 2\n");
	imprimeNivel(quatro,2);
}