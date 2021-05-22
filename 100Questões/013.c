#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void truncW (char t[], int n){
    int i, j = 0, rep = n;
    
    for(i = 0; t[i] != '\0'; i++){
        if(t[i] == ' '){
            t[j] = ' ';
            j++;
            rep = n;
        } else {
            if (rep != 0){
                t[j] = t[i];
                j++;
                rep--;
            }
        }
    }
    t[j] = '\0';
}

void main(){
    char teste[36] = "liberdade, igualdade e fraternidade";
    truncW(teste,4);
    puts(teste);
}