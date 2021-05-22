#include <stdio.h>

void main(){
	int read;
	int sum = 0;
	int n = 0;
	double avg;

	do{
		printf("Insert value (0 to end): ");
		scanf("%d",&read);
		
		if(read != 0){
			sum += read;
			n++;	
		}

	} while(read != 0);

	avg = (double) sum/n;

	printf("\nAverage = %.2f\n", avg);
}