#include <stdio.h>

int bitsUm (unsigned int x){
    int r=0;
    while (x != 0){
        if(x % 2 == 0) x /= 2;
        else { x /= 2; r++;}
    }
    return r;
}
