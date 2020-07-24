#include <stdio.h>
#include <string.h>

int remRep (char texto [])
{
    int i, j;
    
    for(i=0; texto[i]!='\0'; i++)
    {
        if(texto[i+1]==texto[i])
        {
            for(j=i; texto[j]!='\0'; j++)
            {
                texto[j]=texto[j+1];
            }
            texto[j]='\0';
            i--;
        }
    }
    
    return strlen(texto);
}
