#include <stdio.h>

int maiorPrefixo(char s1[], char s2[]){
	int i = 0;
	while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]){
		i++;
	}
	return i;
}

void main(){
    char teste1[11] = "aabbcccaac";
    char teste2[4] = "abc";
    int q = maiorPrefixo(teste1,teste2);
    printf("tamanho do prefixo comum = %d\n",q);
}