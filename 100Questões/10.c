#include <stdio.h>

char * mystrstr(char s1[], char s2[])
{
	int i,j = 0, pos=0;
	
	if (s2[0] == '\0') return s1;
	
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == s2[0]) pos=i;
		
		if (s1[i] == s2[j]) j++;
		
		if (s2[j] == '\0') return s1+pos;
	    
	}
	return NULL;
}
