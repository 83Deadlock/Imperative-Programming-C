#include <stdio.h>

int comunsOrd (int a[], int na, int b[], int nb){
    int i,j,n=0;
    for(i=0,j=0;i<na && j<na;i++,j++){
        if(a[i] == b[j]) n++;
        else if(a[i] < b[j]){
            j--;
        }
        else if(a[i] > b[j]){
            i--;
        }
    }
    return n++;
}
