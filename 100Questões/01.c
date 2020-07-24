#include <stdio.h>

int main() {
    int n,maior;
    printf("Insira uma sequência de números acabada em 0: ");
    scanf("%d", &maior);
    do
    {
        scanf("%d",&n);
        if (n > maior) maior = n;
    } while (n != 0);
    printf("-----\nO maior número da sequência é: %d\n",maior);
    return 0;
}
