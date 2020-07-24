#include <stdio.h>
#include "posicao.h"

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i,r=0;
    for(i=0;(inicial.x != final.x) || (inicial.y != final.y);i++){
        if (inicial.x < final.x){
            mov[i]=Este;
            inicial.x++;
        }
        else if (inicial.x > final.x){
            mov[i]=Oeste;
            inicial.x--;
        }
        else if (inicial.y < final.y){
            mov[i]=Norte;
            inicial.y++;
        }
        else if (inicial.y > final.y){
            mov[i]=Sul;
            inicial.y--;
        }
        r++;
    }
    if(r>N)r=-1;
    return r;
}
