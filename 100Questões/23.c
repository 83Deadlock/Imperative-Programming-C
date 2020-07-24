#include <stdio.h>
#include <string.h>

int palindroma (char s[]) {
    char t[strlen(s)];
    int i = 0, j = strlen(s) - 1;
    for (i=0;s[i] != '\0';i++){
        t[j] = s[i];
        j--;
    }
    t[strlen(s)] = '\0';
    for(i=0,j=0;s[i] != '\0' && t[j] != '\0';i++,j++){
        if(s[i] != t[j]) return 0;
    }
    return 1;
}
