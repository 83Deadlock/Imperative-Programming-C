#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcat(char s1[], char s2[])
{
    
    int i=strlen(s1), j;
    
    for (j=0;s2[j]!='\0';j++)
    {
        s1[i]=s2[j];
        i++;
    }
    
    s1[i]='\0';
    
    return s1;
}
