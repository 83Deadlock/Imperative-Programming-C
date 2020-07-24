#include <stdio.h>

int minInd (int v[], int n) {
   int i,k,r;
   k=v[0];
   for(i=0;i<n;i++){
       if(v[i] < k){
           k=v[i];
           r=i;
       }
   }
   return r;
}
