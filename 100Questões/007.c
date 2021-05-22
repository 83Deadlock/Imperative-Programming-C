#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlen1(char s[]){
    int size = 0;
    for(size = 0; s[size] != '\0'; size++);
    return size;
}

char * strcat1(char s1[], char s2[]){
	int lenF = strlen1(s1) + strlen1(s2) + 1;
	int a = 0;
	int i = 0;

	char* ret = malloc(sizeof(char)*lenF);

	while(s1[a] != '\0'){
		ret[i++] = s1[a++];
	}
	a = 0;
	while(s2[a] != '\0'){
		ret[i++] = s2[a++];
	}
	ret[i] = '\0';
	
	return ret;
}

void main(){
	char* s1 = "aaaaaaaaaaaaaaaaaaaaaa";
	char* s2 = "Ola";

	char* s3 = strcat1(s1,s2);
	puts(s3);
}