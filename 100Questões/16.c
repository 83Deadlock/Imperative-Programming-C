#include <stdio.h>
#include <stdlib.h>

int diff(int i,int j, char s[]){
    while (i<j){
        if(s[i] == s[j]) return 0;
        i++;
    }
    return 1;
}


int difConsecutivos(char s[]){
    int i,j;
    int n = 0;
    int r = 0;
    for(i=0; s[i] != '\0';i++){
        r = 0;
        for (j = i;s[j] != '\0' && diff(i,j,s); j++){
            r++;
        }
        if(r > n){
            n = r;
        }
    }
    return n;
}
