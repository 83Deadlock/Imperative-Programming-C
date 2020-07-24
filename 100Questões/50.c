#include "vizinhos.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct posicao {int x, y;} Posicao;

int vizinhos (Posicao p, Posicao pos[], int N)
{
    int i, n=0;
    
    for(i=0; i<N; i++)
    {
        if ((pos[i].x == p.x) && (pos[i].y == p.y + 1)) n++;
        
        else if ((pos[i].x == p.x) && (pos[i].y == p.y - 1)) n++;
        
        else if ((pos[i].y == p.y) && (pos[i].x == p.x + 1)) n++;
        
        else if ((pos[i].y == p.y) && (pos[i].x == p.x - 1)) n++;
    }
    
    return n;
}
