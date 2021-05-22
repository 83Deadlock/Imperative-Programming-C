#include <stdio.h>
#include <string.h>

int isVowel(char v){
    if (v==65 || v==69 || v==73 || v==79 || v==85 || v==97 || v==101 || v==105 || v==111 || v==117) return 1;
    else return 0;
}

void myStrNov(char s[]){
	int i,j;
	int n = strlen(s);
	char aux[n];
	strcpy(aux,s);

	for(i = 0, j = 0; aux[i] != '\0'; i++){
		if(!(isVowel(aux[i]))){
			s[j] = aux[i];
			j++;
		}
	}
	s[j] = '\0';
}

void main(){
	char s[9] = "Daaaaaat";
	myStrNov(s);
	puts(s);
}