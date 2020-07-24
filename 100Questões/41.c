#include <stdio.h>

void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            a[i][j] = a[i][j] + b[i][j];
        }
    }
}
