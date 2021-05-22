#include <stdio.h>
#include <limits.h>

void main(){
	int read;
	int max = INT_MIN;
	do{
		printf("Insert value (0 to end): ");
		scanf("%d",&read);
		if(read > max && read != 0){
			max = read;
		}
	} while(read != 0);
	printf("\nMaximum Value found = %d\n",max);
}