#include <stdio.h>

//Esta ficha tem os mecanismos de resolução no enunciado de forma mais detalhada

// Ficha 2 - PI 2019/20

float multInt1(int n, float m){
    float r = 0;
    for(int i = 0; i < n; i++){
        r += m;
    }
    return r;
}

float multInt2(int n, float m){
    float r = 0; //Variável à qual vamos somando os valores que m toma durante a execução do processo
    while(n != 1){ //Temos de parar o processo quando o n chega a 1
        if(n % 2 != 0) r += m;
        n = n / 2;
        m = m * 2;
    }
    r += m;
    return r;
}

int mdc1(int a, int b){
    int min,max,div;
    if(a == b){
        return a;
    } else if (a < b){
        min = div = a;
        max = b;
    } else if (b < a){
        min = div = b;
        max = a;
    }
    while(div != 0){
        if(max % div == 0 && min % div == 0){
            return div;
        } else {
            div--;
        }
    }
    return -1;
}

int mdc2(int a, int b){ //Este algoritmo não contempla os casos em que não existe mdc!!
    if(a == b){
        return a;
    }
    else if(a > b){
        mdc2(a-b,b);
    }
    else if (b > a){
        mdc2(a,b-a);
    }
}

int mdc3(int a, int b){ //Este algoritmo não contempla os casos em que não existe mdc!!
    if(a == b){
        return a;
    }
    else if(a > b){
        mdc2(a%b,b);
    }
    else if (b > a){
        mdc2(a,b%a);
    }
}

int fib1(int n){
    int f;
    if(n < 3){
        return 1;
    } else {
        f = fib1(n-1) + fib1(n-2);
    }
    return f;
}

int fib2(int n){
    if(n < 3) return 1;
    else{
        int i = 3;
        int val1 = 1;
        int val2 = 1;
        int aux;
        while(i != n){
            aux = val2;
            val2 += val1;
            val1 = aux;
            i++;
        }
        return val2 + val1;
    }
}

int main() {
    printf("Questão a executar: ");
    int q;
    scanf("%d",&q);

    //Pergunta 1 e 2
    int n;
    float m,r;

    //Pergunta 3, 4 e 5
    int a,b;
    int mdc;

    //Pergunta 6 (a) e 6 (b)
    int f; //A n usada é a das perguntas 1 e 2

    switch (q) {
        case 1:
            printf("Insira um inteiro: ");
            scanf("%d",&n);
            printf("Insira o valor a ser multiplicado: ");
            scanf("%f",&m);
            r = multInt1(n,m);
            printf("%d * %2.f = %.2f\n",n,m,r);
            break;
        case 2:
            printf("Insira um inteiro: ");
            scanf("%d",&n);
            printf("Insira o valor a ser multiplicado: ");
            scanf("%f",&m);
            r = multInt2(n,m);
            printf("%d * %2.f = %.2f\n",n,m,r);
            break;
        case 3:
            printf("Insira um inteiro: ");
            scanf("%d",&a);
            printf("Insira um inteiro: ");
            scanf("%d",&b);
            mdc = mdc1(a,b);
            printf("mdc = %d\n",mdc);
            break;
        case 4:
            printf("Insira um inteiro: ");
            scanf("%d",&a);
            printf("Insira um inteiro: ");
            scanf("%d",&b);
            mdc = mdc2(a,b);
            printf("mdc = %d\n",mdc);
            break;
        case 5:
            printf("Insira um inteiro: ");
            scanf("%d",&a);
            printf("Insira um inteiro: ");
            scanf("%d",&b);
            mdc = mdc3(a,b);
            printf("mdc = %d\n",mdc);
            break;
        case 6:
            printf("Calcular o elemento de ordem: ");
            scanf("%d",&n);
            f = fib1(n);
            printf("método 1 -> %d\n",f);
            f = fib2(n);
            printf("método 2 -> %d\n",f);

    }
}
