#include <stdio.h>
#include <stdlib.h>

/* Pergunta 1
 * a) Output:
 * 			1 1 4
 *			2 2 6
 *			3 3 8
 * 			4 4 10
 *			5 5 12
 *
 * b) Output: 13
 */

void e1a(){
	int x [15] = {1,  2, 3, 4, 5,
                  6,  7, 8, 9,10,
                  11,12,13,14,15};
    int *y, *z, i;
    y = x; 
    z = x+3;
    for (i=0; i<5; i++) {
      printf ("%d %d %d\n", 
              x[i], *y, *z);
      y = y+1; z = z+2;
    }
}

void e1b(){
	int i, j, *a, *b;
    
  	i=3; j=5;
  	a = b = 42;
  	a = &i; b = &j;
  	i++;
  	j = i + *b;
 	b = a;
  	j = j + *b;
  	printf ("%d\n", j);
}

void swapM (int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void swap(int v[], int i, int j){
	swapM(v+i,v+j);
}

int soma(int v[], int N){
	int r = 0;
	N--;
	while(N >= 0){
		r += v[N--];
	}
	return r;
}

void inverteArray1(int v[], int N){
	int i = 0;
	int j = N-1;
	while(i < j){
		swap(v,i,j);
		i++;
		j--;
	}
}

void inverteArray2(int v[], int N){
	int i = 0;
	int j = N-1;
	while(i < j){
		swapM(v+i,v+j);
		i++;
		j--;
	}
}

int maximum (int v[], int N, int* m){
	int r = 0;
	if(N <= 0){
		r = -1;
	} else {
		int max = v[0];
		for(int i = 1; i < N; i++){
			if(v[i] > max) max = v[i];
		}
		*m = max;
	}
	return r;
}

void quadrados(int q[], int N){
	q[0] = 0;
	for(int i = 1; i < N; i++){
		q[i] = q[i-1] + ((2 * (i-1))+1);
	}
}

void pascal (int v[], int N) {
    int k,j;
    for (j=0;j<=N;j++) {
        v[j] = 1;
        if (j >= 2) {
            for (k = (j - 1); k > 0; k--) {
                v[k] = v[k] + v[k - 1];
            }
        }
    }
    for (k=0;k<=N;k++){
        printf("%d ",v[k]);
    }
}

void printPascal(int n){ 
	for (int line = 1; line <= n; line++){ 
		int C = 1; // used to represent C(line, i) 
		for (int i = 1; i <= line; i++){ 
			printf("%d ", C); // The first value in a line is always 1 
			C = C * (line - i) / i; 
		} 
		printf("\n"); 
	} 
} 



void main(){
	int q = -1;
	int a,b,i,j,m,r,l;
	int teste[10] = {0,1,2,3,4,5,6,7,8,9};
	int quad[10];
	while(q != 0){
		printf("\n\n------------------------\n\n");
		printf("Pergunta a executar: ");
		scanf("%d",&q);
		switch(q){
			case 1: printf("a)---------------------------\n");
					e1a();
					printf("-----------------------------\n");
					printf("b)---------------------------\n");
					e1b();
					printf("-----------------------------\n");
					break;
			case 2: printf("Insira dois números inteiros\n");
					printf("a = ");
					scanf("%d",&a);
					printf("b = ");
					scanf("%d",&b);
					swapM(&a,&b);
					printf("\n\na = %d || b = %d\n\n",a,b);
					break;
			case 3:	printf("Indíces para trocar\n");
					printf("i = ");
					scanf("%d",&i);
					printf("j = ");
					scanf("%d",&j);
					for(int k = 0; k < 10; k++){
						printf("| %d |",teste[k]);
					}
					printf("\n-----------\nSUBSTITUINDO %d com %d\n-----------\n",teste[i],teste[j]);
					swap(teste,i,j);
					for(int k = 0; k < 10; k++){
						printf("| %d |",teste[k]);
					}
					break;
			case 4: printf("\n\nA soma de todos os valores do array é %d\n\n",soma(teste,10));
					break;
			case 5: printf("\n-----------\nESTADO INICIAL\n-----------\n");
					for(int k = 0; k < 10; k++){
						printf("| %d |",teste[k]);
					}
					printf("\n-----------\n1ª INVERSÃO\n-----------\n");
					inverteArray1(teste,10);
					for(int k = 0; k < 10; k++){
						printf("| %d |",teste[k]);
					}
					printf("\n-----------\n2ª INVERSÃO\n-----------\n");
					inverteArray2(teste,10);
					for(int k = 0; k < 10; k++){
						printf("| %d |",teste[k]);
					}
					break;
			case 6: r = maximum(teste,10,&m);
					if(r == 0){
						printf("O maior elemento do array é %d\n",m);	
					} else {
						printf("Array vazio");
					}
					break;
			case 7: quadrados(quad,10);
					for(int k = 0; k < 10; k++){
						printf("| %d |",quad[k]);
					}
					break;
			case 8: printf("linha to triangulo de pascal a apresentar: ");
					scanf("%d",&l);
					pascal(quad,l);
					printf("\n-----------\nTRIÂNGULO DE PASCAL\n-----------\n");
					printPascal(l);
					break;
			case 0: printf("A terminar...\n");
					break;
			default: printf("Opção inválida\n");
					 break;
		}
	}
}