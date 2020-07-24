#include "posicao.h"
#include <stdio.h>


Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for(i=0;i<N;i++){
        if(mov [i] == Norte) inicial.y++;
        else if(mov[i] == Este) inicial.x++;
        else if(mov[i] == Sul) inicial.y--;
        else if(mov[i] == Oeste) inicial.x--;
    }
    return inicial;
}
