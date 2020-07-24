#include <stdio.h>

int triSup (int N, int m [N][N]) {
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i>j && m[i][j] != 0) return 0;
        }
    }
    return 1;
}
