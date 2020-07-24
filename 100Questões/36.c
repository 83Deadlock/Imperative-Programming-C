#include <stdio.h>
#include <stdlib.h>

int comuns (int a[],int na,int b[],int nb)
{
    int i = 0,j = 0, counter = 0,flag;
    for(i=0;i<na;i++){
        flag = 0;
        for(j=0;j<nb && !flag;j++){
            if(a[i] == b[j]){
                counter++;
                flag = 1;
            }
        }
    }
    return counter;
}
