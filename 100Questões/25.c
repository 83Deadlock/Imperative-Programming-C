#include <stdio.h>
#include <string.h>

int limpaEspacos (char texto[]) {
    int i=0,j=0;
    for (i=0;texto[i] != '\0';i++){
        while(texto[i] == ' ' && texto[i+1] == ' '){
            for(j=i;texto[j] != '\0'; j++){
                texto[j]=texto[j+1];
            }
        }
    }
    return strlen(texto);
}
