#include <stdio.h>

char* mystrstr(char s1[], char s2[]){
	int i, j, flag = 0;
	int posInicial = -1;

	if(s2[0] == '\0') return s1;

	for(i = 0; s1[i] != '\0' && flag == 0; i++){
		if(s1[i] == s2[0]){
			j = 1;
			posInicial = i;
			for(; s2[j] != '\0' && s1[i+j] == s2[j]; j++);
			if(s2[j] == '\0') flag = 1;
			else posInicial = -1;
		}
	}
	if(posInicial == -1) return NULL;

	return s1+posInicial;
}

int main() {

  char s1[8] = "ooolaaa";
  char s2[4] = "ola";
  
  char * ret = mystrstr(s1,s2);
  
  printf("%s\n",ret);
  
  return 0;
}