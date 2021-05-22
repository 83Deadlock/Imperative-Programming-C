#include <stdio.h>
#include <string.h>

int strlen1(char s[]){
    int size = 0;
    for(size = 0; s[size] != '\0'; size++);
    return size;
}

int mystrcmp(char a[], char b[]){
	int sA = 0;
	int sB = 0;
	int lA = strlen1(a);
	int lB = strlen1(b);
	int iA = 0;
	int iB = 0;

	for(; iA < lA || iB < lB; iA++, iB++){
		if(iA < lA){
			sA += a[iA];
		}
		if(iB < lB){
			sB += b[iB];
		}
			
	}
	return sA - sB;

}

void main(){
	printf("Original = %d\n",strcmp("dada","dada"));
	printf("Minha = %d\n",mystrcmp("dada","dada"));
	
}