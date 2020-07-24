#include <stdio.h>

int maisFreq (int v[], int N){
    int i,j,max=v[0],n=0,c;
    for(i=0;i < N; i++){
        c = 0;
        for(j=0;j < N; j++){
            if(v[i] == v[j]) c++;
        }
        if (c > n){
            max=v[i];
            n=c;
        }
    }
    return max;
}
