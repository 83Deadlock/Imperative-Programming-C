#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int contaPal (char s[])
{
    int i, pal=0;
    
    for(i=0; s[i]!='\0'; i++)
    {
        if ((!(isspace(s[i]))) && (isspace(s[i+1]) || s[i+1]=='\0')) pal++;
    }
    
    return pal;
}
