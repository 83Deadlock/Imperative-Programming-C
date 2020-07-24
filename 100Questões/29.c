#include <stdio.h>
#include <stdlib.h>

int retiraNeg (int v[], int N)
{
    int i = 0, j;
    
    for(i = 0;i < N;i++)
    {
        if (v[i] < 0)
        {
            for(j = i;j < N;j++)
            {
                v[j] = v[j+1];
            }
            N--;
            i--;
        }
    }
    return N;
}
