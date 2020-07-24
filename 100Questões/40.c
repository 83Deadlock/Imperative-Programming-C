#include <stdio.h>

void transposta (int N, float m [N][N]) {
    float z [N][N];
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            z[j][i]=m[i][j];
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            m[i][j]=z[i][j];
        }
    }
}
