#include <stdio.h>

int crescente (int a[], int i, int j){
    int r = 0,k;
    for(k=i;k < j;k++){
        if(a[k] > a[k+1]) return 0;
    }
    return 1;
}
