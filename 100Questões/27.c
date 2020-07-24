#include <stdio.h>
#include <stdlib.h>

void merge (int r [], int a[], int b[], int na, int nb)
{
    int i, j=0, k=0;
    
    for(i=0; j+k<na+nb ; i++)
    {
        if (j==na)
        {
            r[i]=b[k];
            k++;
        }
        
        else if (k==nb)
        {
            r[i]=a[j];
            j++;
        }
        
        else
        {
            if (a[j]<b[k])
            {
                r[i]=a[j];
                j++;
            }
            
            else 
            {
                r[i]=b[k];
                k++;
            }
        }
        
    }
}
