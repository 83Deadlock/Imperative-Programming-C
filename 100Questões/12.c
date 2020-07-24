#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isVowel(char v)
{
    if (v==65 || v==69 || v==73 || v==79 || v==85 || v==97 || v==101 || v==105 || v==111 || v==117) return 1;
    else return 0;
}

void strnoV (char t[])
{
    int i, j, n=strlen(t);
    char s[n];
    strcpy(s, t);
    
    for(i=0, j=0 ; s[i]!='\0'; i++)
    {
        if (!(isVowel(s[i])))
        {
            t[j]=s[i];
            j++;
        }
    }
    t[j]='\0';
} 
