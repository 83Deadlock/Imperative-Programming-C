#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
	int numero;
	char nome[100];
	int miniT[6];
	float teste;
} Aluno;

float miniTestes(int miniT[]){
	int sum = 0;
	for(int i = 0; i < 6; i++){
		sum += miniT[i];
	}
	return ((float) sum/2);
}

float nota (Aluno a){
	return (miniTestes(a.miniT) + (a.teste * 0.7));
}

int procuraNum(int num, Aluno t[], int N){
	int r = -1;
	int flag = 0;
	int i;
	for(i = 0; i < N && !flag; i++){
		if(t[i].numero == num) flag = 1;
	}
	if(i != N) r = i;
	return r;
}

int procuraNum2(int num, int ind[], Aluno t[], int N){
	int flag = -1;
	int topped = 0;
	for(int i = 0; i < N && flag == -1 && topped == 0; i++){
		if(t[ind[i]].numero == num){
			flag = ind[i];
		} else if (t[ind[i]].numero > num){
			topped = 1;
		}
	}
	return flag;
}

void swapAlunos(Aluno t[], int i, int j){
	Aluno temp = t[i];
	t[i] = t[j];
	t[j] = temp;
}

void ordenaPorNum (Aluno t[], int N){
	for(int i = 0; i < N; i++){
		int indMin = i;
		int numMin = t[i].numero;
		for(int j = i + 1; j < N; j++){
			if(t[j].numero < numMin){
				numMin = t[j].numero;
				indMin = j;
			}
		}
		if(indMin != i){
			swapAlunos(t,i,indMin);
		}
	}
}

int elem(int ind[], int e, int N){
	int flag = -1;
	int i;
	for(i = 0; i < N && flag == -1; i++){
		if(ind[i] == e) flag = i;
	}
	return flag;
}

int minIndex(int v[], int N){
	int min = v[0];
	int index = 0;
	for(int i = 1; i < N; i++){
		if(v[i] < min){
			min = v[i];
			index = i;
		}
	}
	return index;
}

void criaIndPorNum (Aluno t[], int N, int ind[]){
	int numeros[N];

	for(int i = 0; i < N; i++){
		numeros[i] = t[i].numero;
	}

	int aux;
	
	for(int i = 0; i < N; i++){
		aux = minIndex(numeros,N);	
		ind[i] = aux;
		numeros[aux] = 10000;
	}
}

void printAluno(Aluno a){
	printf("\t{\n");
	printf("\t\tNumero: %d,\n",a.numero);
	printf("\t\tNome: %s,\n",a.nome);
	printf("\t\tNotas: ");
	printf("{");
    for(int i = 0; i < 6; i++){
    	if(i!=5) printf("%d,",a.miniT[i]);
    	else printf("%d",a.miniT[i]);
    }
    printf("},\n");
    printf("\t\tTeste: %.2f\n",a.teste);
    printf("\t}");
}

void imprimeTurma (int ind[], Aluno t[], int N){
	printf("{\n");
	for(int i = 0; i < N; i++){
		printAluno(t[ind[i]]);
		if(i + 1 != N) printf(",\n");
		else printf("\n");
	}
	printf("}\n");
}

int minString (char* nomes[], int N){
	char min[100];
	strcpy(min,nomes[0]);
	int res = 0;
	printf("\n");
	for(int i = 0; i < N; i++){
		printf("nomes[%d] = %s\n",i,nomes[i]);
		if(strcmp(min,nomes[i]) > 0){
			strcpy(min,nomes[i]);
			res = i;
		}
	}
	printf("\nMenor string : %s\n",min);
	return res;
}

void criaIndPorNome(Aluno t[], int N, int ind[]){

	char* nomes[N];
	for(int i = 0; i < N; i++){
		nomes[i] = malloc(sizeof(char)*100);
		strcpy(nomes[i],t[i].nome);
	}
	int aux;

	for(int i = 0; i < N; i++){
		aux = minString(nomes,N);
		ind[i] = aux;
		strcpy(nomes[aux],"zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
	}
}

int main() {
    Aluno Turma1 [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       } ;
    int indNome [7], indNum [7];
    int i;
    
    printf ("\n-------------- Testes --------------\n");
    
    //printf("Nota do André -> %.2f\n",nota(Turma1[0]));

    //ordenaPorNum (Turma1, 7);
    //printf ("procura 5555: %d \n", procuraNum (5555, Turma1, 7));
    //printf ("procura 9999:%d \n", procuraNum (9999, Turma1, 7));

    //for (i=0; i<7; imprimeAluno (Turma1 + i++));
    
    //criaIndPorNum (Turma1, 7, indNum);
    //printf("{");
    //for(i = 0; i < 7; i++){
    //	if(i!=6) printf("%d,",indNum[i]);
    //	else printf("%d",indNum[i]);
    //}
    //printf("}\n");
    
    //imprimeTurma(indNum,Turma1,7);

    //printf ("procura 6666:%d \n",  procuraNum2 (6666, indNum, Turma1, 7));
    //printf ("procura 9999:%d \n",  procuraNum2 (9999, indNum, Turma1, 7));

    //criaIndPorNome (Turma1, 7, indNome);
    //printf("{");
    //for(i = 0; i < 7; i++){
    //	if(i!=6) printf("%d,",indNome[i]);
    //	else printf("%d",indNome[i]);
    //}
    //printf("}\n");
    
    //imprimeTurma (indNum, Turma1, 7);
    
    //imprimeTurma (indNome, Turma1, 7);

    printf ("\n---------- Fim dos Testes ----------\n");
    
    return 0;
}
