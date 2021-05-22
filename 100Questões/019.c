#include <stdio.h>
#include <string.h>

int igual (char s1[], char s2[], int i){
    int j;
    for(j = 0; s1[i] != '\0'; i++, j++){
        if(s1[i] != s2 [j]) return 0;
    }
    return 1;
}

int sufPref (char s1[], char s2[]){
    int i, sp = 0;
    
    for(i = 0; s1[i] != '\0'; i++){
        if (s1[i] == s2[0]){
            if(igual(s1, s2, i)) break;
        }
    }
    
    while (s1[i]!='\0'){
        i++;
        sp++;
    }

    return sp;
}

void main(){
	char a[7] = "batota";
	char b[11] = "totalidade";
	int q = sufPref(a,b);
	printf("q = %d\n",q);
}