#include <stdio.h>

// 83      			1010011      
// 83/2 = 41        0101001
// 41/2 = 20		0010100
// 20/2 = 10		0001010
// 10/2 = 5 		0000101
//  5/2 = 2			0000010
//  2/2 = 1			0000001

int bitsUm(int n){
	int r = 0;
	while(n != 0){
		if(n % 2 == 0){
			n /= 2;
		} else{
			r++;
			n /= 2;
		}
	}
	return r;
}

void main(){
	int n,res;
	printf("Insert a value: ");
	scanf("%d",&n);
	res = bitsUm(n);
	printf("\n%d has %d bits with value 1.\n",n,res);
}