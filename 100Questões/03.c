#include <stdio.h>

int q3() {
    int x;
    int maior1;
    int maior2;
    scanf("%d",&maior1);
    maior2 = maior1;
    do
    {
        scanf("%d",&x);
        if (x > maior1 && x > maior2){
            maior2 = maior1;
            maior1 = x;
        }
        else if (x > maior2 && x < maior1) maior2 = x;
    } while (x != 0);
    printf("-------\nO segundo maior elemento é: %d",maior2);
    return 0;
}
