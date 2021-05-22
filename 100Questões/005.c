#include <stdio.h>

// 8    1000

int trailingZ (unsigned int n) {
	int r = 0;
    if (n % 2 == 1) return 0;
    while (n % 2 == 0) {
        n = n / 2;
        r++;
    }
    return r;
}

void main(){
	int n,res;
	printf("Insert a value: ");
	scanf("%d",&n);
	res = trailingZ(n);
	printf("\n%d has %d bits with value 0 at the end of the binary representation.\n",n,res);
}