#include <stdio.h>
#include <stdlib.h>

int temRep (int v[], int n, int x)
{
    int i;
    
    for(i=0; i<n; i++)
    {
        if (v[i]==x) return 1;
    }
    return 0;
}

int elimRep (int v[], int N)
{
    int i, j;
    
    for(i=0; i<N; i++)
    {
        if (temRep(v,i,v[i]))
        {
            for(j=i; j<N; j++){
                v[j]=v[j+1];
            } 
            N--;
            i--;
        }
    }
    return N;
}
