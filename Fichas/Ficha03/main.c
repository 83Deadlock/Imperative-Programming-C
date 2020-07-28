#include <stdio.h>
#include <stdlib.h>

//Esta ficha tem algumas perguntas teóricas respondidas em comentário abaixo.

/* Ficha 3 - PI 2019/20
 * Pergunta 1
 * a) - "1, 1, 4
 *       2, 2, 6
 *       3, 3, 8
 *       4, 4, 10
 *       5, 5, 12"
 *
 * b)- "13"
 *
 */

void swapM(int *x, int *y){
    int aux;
    aux = *y;
    *y = *x;
    *x = aux;
}

void swap (int v[], int i, int j){
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int soma (int v[], int N){
    int res = 0;
    for(int i = 0; i < N; i++){
        res += v[i];
    }
    return res;
}

int maximum(int v[], int N, int *m){
    if(N <= 0){
        *m = -1;
        return -1;
    }
    int max = v[0];
    for(int i = 1; i < N; i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    *m = max;
}

void quadrados(int q[], int N){
    for(int i = 0; i < N; i++){
        q[i] = i * i;
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
    for (k=0;k<=N;k++)
        printf("%d\n",v[k]);
}

int main() {
    int opt;
    printf("Pergunta a realizar: ");
    scanf("%d",&opt);
    //Pergunta 2
    int x = 3, y = 5;

    //Pergunta 3, 4, 5 e 6
    int N = 10;
    int v[10] = {0,1,2,3,4,5,6,7,8,9};
    int i = 1, j = 9;
    int sum;
    int max;
    int q[10];

    //Pergunta 7
    int teste[6] = {9,71,41,21,9,7};

    switch(opt){
        case 2:
            printf("x = %d - y = %d\n",x,y);
            swapM(&x,&y);
            printf("Swapping\n");
            printf("x = %d - y = %d\n",x,y);
            break;
        case 3:
            printf("v[i] = %d - v[j] = %d\n",v[i],v[j]);
            swap(v,i,j);
            printf("v[i] = %d - v[j] = %d\n",v[i],v[j]);
            break;
        case 4:
            sum = soma(v,N);
            printf("%d\n",sum);
            break;
        case 5:
            maximum(v,N,&max);
            printf("MAX = %d\n",max);
            break;
        case 6:
            quadrados(q,N);
            for(int i = 0; i < N; i++){
                printf("q[%d] -> %d\n",i,q[i]);
            }
            break;
        case 7:
            pascal(teste,7);
            break;
        default:
            break;
    }
    return 0;
}
