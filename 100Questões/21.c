#include <stdio.h>
#include <string.h>

int contaVogais (char s[]) {
    int i = 0,v = 0;
    for(i=0;s[i] != '\0'; i++){
        if((toupper(s[i])) == 'A' || (toupper(s[i])) == 'E' || (toupper(s[i])) == 'I' || (toupper(s[i])) == 'O' || (toupper(s[i])) == 'U') v++;
    }
    return v;
}
