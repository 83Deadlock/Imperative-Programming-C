#include <stdio.h>

int cardinalMSet (int N, int v[N]){
    int i,r=0;
    for(i=0;i<N;i++){
        r+=v[i];
    }
    return r;
}
