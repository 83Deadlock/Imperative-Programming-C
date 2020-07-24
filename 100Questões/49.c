#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct posicao {int x, y;} Posicao;

int distancia (Posicao n)
{    
    return (abs(n.x) + abs(n.y));
}

int maiscentral (Posicao pos[], int N)
{
    int i, n=0, min=distancia(pos[0]);
    
    for(i=0; i<N; i++)
    {
        if (distancia(pos[i]) < min)
        {
            min = distancia(pos[i]);
            n=i;
        }
    }
    return n;
}
