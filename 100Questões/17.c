#include <stdio.h>

int maiorPrefixo (char s1 [], char s2 []) {
    int i = 0, n = 0;
    for (i=0;s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i];i++){
        n++;
    }
    return n;
}
