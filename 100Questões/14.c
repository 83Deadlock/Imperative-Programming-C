#include <stdio.h> 

char charMaisfreq(char s[]){
    int i,j; //Variáveis usadas para percorrer o array
    int r = 0; //Variável que vai contar cadas vezes ocorre um char.
    int n = 0; //Variável que marca o maior numero de ocorrências de um char.
    char c;
    for(i=0; s[i] != '\0';i++){ //Percorre o array "selecionando" um char de cada vez
        r = 0;
        for(j=0;s[j] != '\0';j++){ //Percorre o array verificando quantas vezes o char ocorre
            if (s[i] == s[j]) r++;
        }
    if (r > n){ 
        n = r;
        c = s[i];
    }    
    }
    return c;
}
