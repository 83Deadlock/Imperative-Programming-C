#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void truncW (char t[], int n)
{
    int i, j=0, repetir=n;
    
    for(i=0; t[i]!='\0'; i++)
    {
        if (t[i]==' ')
        {
            t[j]=' ';
            j++;
            repetir = n;
        }
        
        else
        {
            if (repetir!=0)
            {
                t[j]=t[i];
                j++;
                repetir--;
            }
        }
    }
    t[j] = '\0';
}
