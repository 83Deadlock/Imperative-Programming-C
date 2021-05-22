#include <stdio.h>

int mystrlen(char s[]){
	int i = 0;
	while(s[i] != '\0'){
		i++;
	}
	return i-1;
}

char* mystrrev(char s[]){
	int size = mystrlen(s) + 1;
	char new[size];
	int i;
	for(i = 0; s[i] != '\0'; i++){
		new[(size-i-1)] = s[i];
	}
	new[size] = '\0';
	for(i = 0; new[i] != '\0'; i++){
	    s[i] = new[i];
	}
	return s;
}

void main(){
	char s[9] = "Deadlock";
	mystrrev(s);
}