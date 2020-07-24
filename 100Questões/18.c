#include <stdio.h>
#include <string.h>

int maiorSufixo (char s1 [], char s2 []) {
    int i,j,n = 0;
    for (i = strlen(s1) - 1, j = strlen(s2) - 1; i >= 0 && j >=0 ;i--, j--){
        if(s1[i] == s2[j]) n++;
        else i = -1;
    }
    return n;
}
