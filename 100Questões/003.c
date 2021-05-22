#include <stdio.h>
#include <limits.h>

void main(){
	int read;
	int max = INT_MIN + 1;
	int max2 = INT_MIN;
	do{
		printf("Insert value (0 to end): ");
		scanf("%d",&read);

		if(read != 0){
			if(read > max){
				max2 = max;
				max = read;
			} else if(read > max2 && read < max){
				max2 = read;
			}
		}

		
	} while(read != 0);
	printf("\n2nd Highest Value Found = %d\n",max2);
}