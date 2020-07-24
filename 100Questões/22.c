#include <stdio.h>

int aux(char a, char b[]){
    int j;
    for (j=0; b[j] != '\0';j++){
        if(b[j] == a) return 1;
    }
    return 0;
}

int contida (char a[], char b[]) {
    int i = 0,r = 0;
    for(i=0;a[i] != '\0'; i++){
        if (aux(a[i],b) == 0) return 0;
    }
    return 1;
}
