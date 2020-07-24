#include <stdio.h>

int menosFreq (int v[], int N){
    int i,j,min=v[0],n=N,c; //i e j são usadas para percorrer o array, min acumula o numero que ocorre com menor frequencia,n determina o numero minimo de ocorrencias,c serve de contador.
    for(i=0;i < N; i++){
        c = 0;
        for(j=0;j < N; j++){
            if(v[i] == v[j]) c++;
        }
        if (c < n){
            min=v[i];
            n=c;
        }
    }
    return min;
}
