#include <stdio.h>

//Esta ficha tem algumas perguntas teóricas também respondidas neste file

/*   Ficha 1 - PI 2019/20
 *   Pergunta 1
 *
 *   -> Output = "12 16"
 *   -> Output = "0 *um valor aleatório qualquer*"
 *   -> Output = "A 65
 *                B 66 2 50
 *                b 98"
 *   -> Output = "100 200"
 *
 *   Pergunta 2
 *
 *   -> Output = "11 66"
 *   -> Output = SEGMENTATION FAULT devido a loop infinito. x a ser incrementado em 2 unidades nunca vai ter o valor de paragem do ciclo (11)
 *   -> Output = "_#_#_#_#_#_#_#_#_#_#"
 *   -> Output = "abcdefg
 *                bcdefg
 *                cdefg
 *                defg
 *                efg
 *                fg
 *                g"
 *   -> Output = Depende do número passado.
 *   -> Output = "
 *                1
 *                01
 *                11
 *                001
 *                101
 *                011
 *                111
 *                0001
 *                1001
 *                0101
 *                1101
 *                0011
 *                1011
 *                0111
 *                1111"
 */

void quadrado (){
    int size = 0;
    printf("Tamanho do quadrado: ");
    scanf("%d",&size);
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            putchar('#');
        }
        putchar('\n');
    }
}

void xadrez (){
    int size = 0, c = 0;
    printf("Tamanho do tabuleiro: ");
    scanf("%d",&size);
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(c % 2 == 0) putchar('#');
            else putchar('_');
            c++;
        }
        putchar('\n');
    }
}

void vertical (){
    int size = 0;
    printf("Altura do triangulo: ");
    scanf("%d",&size);
    int i = 1;
    for(; i < size; i++){
        for(int j = 0; j < i; j++){
            putchar('#');
        }
        putchar('\n');
    }
    for(; i > 0; i--){
        for(int j = 0; j < i; j++){
            putchar('#');
        }
        putchar('\n');
    }
}

void horizontal (){
    int size = 0;
    printf("Altura do triangulo: ");
    scanf("%d",&size);
    int max = size + (size-1);
    int j;
    for(int i = 0; i < size; i++){
        for(j = 0; j < max / 2 - i; j++){
            putchar(' ');
        }
        for(j = 0; j < (2*i) +1; j++){
            putchar('#');
        }
        for(j = 0; j < max / 2 - i; j++){
            putchar(' ');
        }
        putchar('\n');
    }
}

int main (){
    quadrado();
    xadrez();
    vertical();
    horizontal();
    return 0;
}