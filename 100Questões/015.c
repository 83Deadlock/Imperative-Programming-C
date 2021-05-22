#include <stdio.h>

int iguaisConsecutivos (char s[]) {
    int i, j; 
    int r = 0; 
    int n = 0;
    char c;
    for (i = 0; s[i] != '\0'; i++){
        r = 0;
        for (j = i;s[i] == s[j];j++){
            r++;
        }

        i = i + r - 1;

        if(r > n){
            n = r;
            c = s[i];
        }
    }
    return n;
}

void main(){
    char teste1[10] = "aabcccaac";
    char teste2[4] = "ccc";
    char teste3[4] = "ola";
    int q = iguaisConsecutivos(teste1);
    printf("----------\n%s\n----------\nComprimento da maior sub-string = %d\n",teste1,q);
    q = iguaisConsecutivos(teste2);
    printf("----------\n%s\n----------\nComprimento da maior sub-string = %d\n",teste2,q);
    q = iguaisConsecutivos(teste3);
    printf("----------\n%s\n----------\nComprimento da maior sub-string = %d\n",teste3,q);
}