#include <stdio.h>

void insere (int v[], int N, int x){
    int i,sp;
    for(i = 0; i < N && v[i] < x; i++);
    if(i < N){
        sp = i;
        for(i = N-1; i > sp; i--){
            v[i] = v[i-1];
        }
        v[sp] = x;
    }
}

void iSort (int v[], int N){
    int i;
    for(i = 1; i < N; i++){
        int j = i, x = v[i];
        while(j > 0 && x < v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        v[j] = x;
    }
}

int maxInd (int v[], int N){
    int max = v[0];
    int index = 0;
    for(int i = 1; i < N ; i++){
        if(v[i] > max){
            max = v[i];
            index = i;
        }
    }
    return index;
}

void maxSort (int v[], int N){
    int aux;
    for(int i = N; i > 0; i--){
        int max = maxInd(v,i);
        aux = v[i-1];
        v[i-1] = v[max];
        v[max] = aux;
    }
}

void maxSort2 (int v[], int N){
    int aux;
    int max;
    int index;
    for(int i = N; i > 0; i--){
        max = v[0];
        index = 0;
        for(int j = 1; j < i; j++){
            if(v[j] > max){
                max = v[j];
                index = j;
            }
        }
        aux = v[i-1];
        v[i-1] = v[index];
        v[index] = aux;
    }
}

void swap (int v[], int i, int j){
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int bubble (int v[], int N){
    int i;
    int ret = 0;
    for(i = 1; i < N ; i++){
        if(v[i-1] > v[i])
            swap(v,i-1,i);
            ret = 1;
    }
    return ret;
}

void bubbleSort (int v[], int N){
    for(int i = N; i > 0 ; i--){
        int changes = bubble(v,i);
        if (changes == 0){
            printf("Array ordenado\n");
            break;
        }
    }
}

int main() {
    int opcao;
    printf("Pergunta: ");
    scanf("%d",&opcao);

    //Pergunta 1 - Criei um array ordenado com 10 valores. Vou tentar inserir o 4 na posição certa (i=4) e depois inserir o 11 (não é inserido)
    int N = 10;
    int v[10] = {0,1,2,3,5,6,7,8,9,10};
    int x = 4;
    int y = 11;

    //Pergunta 2 - Dar um array por ordenar e ver o resultado
    int t[10] = {1,4,3,2,7,5,6,8,9,0};

    //Pergunta 3 - Vou usar os arrays criados em cima
    //array v deve devolver o valor 9
    //array t deve devolver o valor 8
    int u[3] = {1000,3,1}; //deve devolver 0
    int res;

    //Pergunta 4 - Vou um array desordenado e vou usar o array u
    int z[5] = {0,4,5,3,99};

    //Pergunta 5 - Igual à pergunta 4

    //Pergunta 6
    char exemplo[] = "Consideremos o array u[3] = [1000,3,1]\n a primeira itoeração vai trocar o 1000 pelo 3 e a segunda o 100 pelo 1, pondo o 1000 na posição certa";

    //Pergunta 7
    //Vou usar os arrays u e v

    //Pergunta 8
    //Vou usar o array v. Se durante a ordenação aparecer "array ordenado" significa que demos uso à optimização.

    switch(opcao){
        case 1:  for(int i = 0; i < N; i++){
                    printf("v[%d] = %d\n",i,v[i]);
                 }

                 insere(v,N,x); printf("Inserção do 4\n");

                 for(int i = 0; i < N; i++){
                    printf("v[%d] = %d\n",i,v[i]);
                 }

                insere(v,N,x); printf("Inserção do 11\n");

                for(int i = 0; i < N; i++){
                    printf("v[%d] = %d\n",i,v[i]);
                }

                 break;

        case 2: for(int i = 0; i < N; i++){
                    printf("t[%d] = %d\n",i,t[i]);
                }
                iSort(t,N); printf("Ordenado\n");
                for(int i = 0; i < N; i++){
                    printf("t[%d] = %d\n",i,t[i]);
                }
                break;

        case 3: res = maxInd(v,10);
                printf("deve dar 9 -> %d\n",res);
                res = maxInd(t,10);
                printf("deve dar 8 -> %d\n",res);
                res = maxInd(u,3);
                printf("deve dar 0 -> %d\n",res);
                break;

        case 4: for(int i = 0; i < 3; i++){
                    printf("u[%d] = %d\n",i,u[i]);
                }
                maxSort(u,3); printf("Ordenado\n");
                for(int i = 0; i < 3; i++){
                    printf("u[%d] = %d\n",i,u[i]);
                }
                printf("----------------------------------\n");
                for(int i = 0; i < 5; i++){
                     printf("z[%d] = %d\n",i,z[i]);
                }
                maxSort(z,5); printf("Ordenado\n");
                for(int i = 0; i < 5; i++){
                    printf("z[%d] = %d\n",i,z[i]);
                }

                break;

        case 5: for(int i = 0; i < 3; i++){
                    printf("u[%d] = %d\n",i,u[i]);
                }
                maxSort2(u,3); printf("Ordenado\n");
                for(int i = 0; i < 3; i++){
                    printf("u[%d] = %d\n",i,u[i]);
                }
                printf("----------------------------------\n");
                for(int i = 0; i < 5; i++){
                    printf("z[%d] = %d\n",i,z[i]);
                }
                maxSort2(z,5); printf("Ordenado\n");
                for(int i = 0; i < 5; i++){
                    printf("z[%d] = %d\n",i,z[i]);
                }

                break;

        case 6: printf("%s\n",exemplo);

                break;

        case 7: for(int i = 0; i < 3; i++){
                    printf("u[%d] = %d\n",i,u[i]);
                }
                bubbleSort(u,3); printf("Ordenado\n");
                for(int i = 0; i < 3; i++){
                    printf("u[%d] = %d\n",i,u[i]);
                }
                printf("----------------------------------\n");
                for(int i = 0; i < 5; i++){
                    printf("z[%d] = %d\n",i,z[i]);
                }
                bubbleSort(z,5); printf("Ordenado\n");
                for(int i = 0; i < 5; i++){
                    printf("z[%d] = %d\n",i,z[i]);
                }

                break;

        case 8: for(int i = 0; i < N; i++){
                    printf("v[%d] = %d\n",i,v[i]);
                }
                bubbleSort(v,N); printf("Ordenado\n");
                for(int i = 0; i < N; i++){
                    printf("v[%d] = %d\n",i,v[i]);
                }

                break;

        default: printf("Saíndo\n");

                 break;
    }
}
