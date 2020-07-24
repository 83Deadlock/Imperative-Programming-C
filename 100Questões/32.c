#include <stdio.h>
#include <stdlib.h>

int maxCresc (int v[], int N)
{
    int i, cont=1, max=1;
    for(i=0; i<N; i++)
    {
        if (v[i+1]>=v[i]) cont++;
        else
        {
            if (cont>max) max=cont;
            cont = 1;
        }
    }
    return max;
}
