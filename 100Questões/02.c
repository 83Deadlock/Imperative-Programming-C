#include <stdio.h>

int q2(){
    int i,num;
    float media;
    printf("Introduza a sequencia terminada com 0.\n");
    scanf("%d",&num);
    i = 0;
    media = 0;
    while (num != 0){
        media = media + num;
        scanf("%d",&num);
        ++i;
    }
    media = media/i;
    printf("A média é %f",media);
    return 0;
}
