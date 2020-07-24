#include <stdio.h>
#include <stdlib.h>

int elimRepOrd (int v[],int N)
{ 
	int i, j = 0, n;
	for (i = 0;i<N;i++)
	{
		if (v[i] != v[j])
		{
			j++;
			v[j] = v[i];
		}
	}
	n=j+1;
	
	return n;
}
