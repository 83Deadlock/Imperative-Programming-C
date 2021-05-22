#include <stdio.h>
#include <stdlib.h>

int strlen1(char s[]){
    int size = 0;
    for(size = 0; s[size] != '\0'; size++);
    return size;
}

char * mystrcpy(char *dest, char src[]){
	int size = strlen1(src) + 1;
	printf("size = %d\n",size);

	dest = malloc(sizeof(char)*size);

	for(int i = 0; i < size-1; i++){
		printf("src[%d] = %c\n",i,src[i]);
		dest[i] = src[i];
	}
	dest[size] = '\0';

	return dest;
}

void main(){
	char s1[3] = "Ola";
	char* s2;

	s2 = mystrcpy(s2,s1);
	puts(s2);
}