#include <stdio.h>

char charMaisFreq(char s[]){
	if(s[0] == '\0') return 0;
	char cMF = s[0];
	int freqMax = 0;
	int i,j,freqAt;
	for(i = 0; s[i] != '\0'; i++){
		freqAt = 0;
		for(j = 0; s[j] != '\0'; j++){
			if(s[i] == s[j]) freqAt++;
		}
		if(freqAt >= freqMax){
			freqMax = freqAt;
			cMF = s[i];
		}
	}
	return cMF;
}

void main(){
	char teste[36] = "liberdade, igualdade e fraternidade";
	char c = charMaisFreq(teste);
	printf("c = %c\n",c);
}