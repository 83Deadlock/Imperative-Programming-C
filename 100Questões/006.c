#include <stdio.h>

int qDig(int n){
	int r = 1;
	while(n % 10 != n){
		r++;
		n /= 10;
	}
	return r;
}

void main(){
	int n,res;
	printf("Insert a value: ");
	scanf("%d",&n);
	res = qDig(n);
	printf("\n%d needs %d numbers to be represented.\n",n,res);
}