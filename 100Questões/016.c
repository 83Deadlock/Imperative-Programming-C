#include <stdio.h>

int diff(int i,int j, char s[]){
    while (i < j){
        if(s[i] == s[j]) return 0;
        i++;
    }
    return 1;
}

//

int difConsecutivos(char s[]){
    int i,j;
    int n = 0;
    int r = 0;
    for(i=0; s[i] != '\0';i++){
        r = 0;
        for (j = i;s[j] != '\0' && diff(i,j,s); j++){
            r++;
        }

        i = i + r - 1;

        if(r > n){
            n = r;
        }
        printf("i = %d\n",i);
    }
    return n;
}

void main(){
    char teste1[11] = "aabbcccaac";
    char teste2[4] = "ccc";
    char teste3[4] = "ola";
    int q = difConsecutivos(teste1);
    printf("----------\n%s\n----------\nComprimento da maior sub-string = %d\n",teste1,q);
    q = difConsecutivos(teste2);
    printf("----------\n%s\n----------\nComprimento da maior sub-string = %d\n",teste2,q);
    q = difConsecutivos(teste3);
    printf("----------\n%s\n----------\nComprimento da maior sub-string = %d\n",teste3,q);
}