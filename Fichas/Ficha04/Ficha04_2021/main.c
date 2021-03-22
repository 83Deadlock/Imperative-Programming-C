#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isVogal(char c){
	int r = 0;
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') r = 1;
	return r;
}

int contaVogais(char* s){
	int i = 0;
	int r = 0;
	while(s[i] != '\0'){
		if(isVogal(s[i])) r++;
		i++;
	}
	return r;
}

int retiraVogaisRep (char* s){
    int i, j;
    int n = strlen(s);
    
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == s[i+1] && isVogal(s[i])){
            for(j = i; s[j] != '\0'; j++){
                s[j] = s[j+1];
            }
            s[j]='\0';
            i--;
        }
    }
    
    return (n - strlen(s));
}

int duplicaVogais(char* s){

	int n = strlen(s);		//Número de elementos base da string argumento
	int v = contaVogais(s);	//Número de elementos que vão ser adicionados à string
	
	s = realloc(s,n+v); 	//Copiamos o conteúdo de s para um bloco de memória com espaço
							//para aguentar as inserções que vão ser feitas
	s[n+v] = '\0';			//Marca o final da nova string
	
	for(n = n-1; n >= 0; n--){	//Preenche a nova string do fim para o início
		if(isVogal(s[n])){		//Se o char for uma vogal
			s[n+v] = s[n];		// coloca o duplicado na última posição que ainda não foi preenchida
			v--;				//Diminui o número de vogais que faltam ser duplicadas
			s[n+v] = s[n];		//  coloca o original na última posição que ainda não foi preenchida
		} else {
			s[n+v] = s[n];		//Se não for vogal preenchemos simplesmente a ultima posição não preenchida
		}
	}
	return (contaVogais(s)/2);
}

int ordenado(int v[], int N){
	int flag = 1;
	for(int i = 0; i < N-1 && flag == 1; i++){
		if(v[i] > v[i+1]) flag = 0;
	}
	return flag;
}

void merge(int a[], int na, int b[], int nb, int r[]){
	int ia,ib;
	ia = ib = 0;
	for(int n = 0; n < na + nb; n++){
		if(ia == na){
			r[n] = b[ib++];
		} else if(ib == nb){
			r[n] = a[ia++];
		} else if(a[ia] <= b[ib]){
			r[n] = a[ia++];
		} else {
			r[n] = b[ib++];
		}
	}
}

void swap(int v[], int a, int b){
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

int partition (int v[], int N, int x){
	int menores = 0;
	for(int i = 0; i < N; i++){
		if(v[i] <= x){
			if(i != menores){
				swap(v,menores,i);
				menores++;
			}
		}
	}
	return menores;
}

void main(){
	char* s1a = malloc(sizeof(char) * 5);
	strcpy(s1a, "abcde");
	char* s1b = malloc(sizeof(char) * 5);
	strcpy(s1b, "bcdfg");
	char* s1c = malloc(sizeof(char) * 10);
	strcpy(s1c, "ola mundo!");

	char* s2a = malloc(sizeof(char) * 38);
	strcpy(s2a, "Estaa e umaa string coom duuuplicadoos");
	char* s2b = malloc(sizeof(char) * 4);
	strcpy(s2b, "aaaa");
	char* s2c = malloc(sizeof(char) * 5);
	strcpy(s2c, "aabaa");

	char* s3a = malloc(sizeof(char) * 15);
	strcpy(s3a, "terceira alinea");
	char* s3b = malloc(sizeof(char) * 10);
	strcpy(s3b, "pergunta 3");
	char* s3c = malloc(sizeof(char) * 12);
	strcpy(s3c, "ultimo teste");

	int a1[10] = {0,1,2,3,4,5,6,7,8,9};
	int a2[10] = {1,0,3,2,5,4,7,6,9,8};
	int a3[10] = {0,1,2,3,4,5,6,7,8,2};

	int b1[10] = {0,2,4,6,8,10,12,14,16,18};
	int b2[10] = {1,3,5,7,9,11,13,15,17,19};
	int b12r[20];
	int b3[10] = {0,1,2,3,4,5,6,7,8,9};
	int b4[10] = {10,11,12,13,14,15,16,17,18,19};
	int b34r[20];

	int c1[10] = {165,4,158,5,154,6,152,9,150,13};
	int c1t = 100;

	int q = -1;
	while(q != 0){
		printf("Pergunta a executar: ");
		scanf("%d",&q);
		switch(q){
			case 1: printf("\n--------------------\n%s -> #vogais = %d\n--------------------\n",s1a,contaVogais(s1a));
					printf("\n--------------------\n%s -> #vogais = %d\n--------------------\n",s1b,contaVogais(s1b));
					printf("\n--------------------\n%s -> #vogais = %d\n--------------------\n",s1c,contaVogais(s1c));
				    break;
			case 2: printf("\n--------------------\nANTES -> %s\n--------------------\n",s2a);
					printf("\n--------------------\n%s -> #reps = %d\n--------------------\n",s2a,retiraVogaisRep(s2a));
					printf("\n--------------------\nANTES -> %s\n--------------------\n",s2b);
					printf("\n--------------------\n%s -> #reps = %d\n--------------------\n",s2b,retiraVogaisRep(s2b));
					printf("\n--------------------\nANTES -> %s\n--------------------\n",s2c);
					printf("\n--------------------\n%s -> #reps = %d\n--------------------\n",s2c,retiraVogaisRep(s2c));
				    break;	  
			case 3: printf("\n--------------------\nANTES -> %s\n--------------------\n",s3a);
					printf("\n--------------------\n%s -> #adds = %d\n--------------------\n",s3a,duplicaVogais(s3a));
					printf("\n--------------------\nANTES -> %s\n--------------------\n",s3b);
					printf("\n--------------------\n%s -> #adds = %d\n--------------------\n",s3b,duplicaVogais(s3b));
					printf("\n--------------------\nANTES -> %s\n--------------------\n",s3c);
					printf("\n--------------------\n%s -> #adds = %d\n--------------------\n",s3c,duplicaVogais(s3c));
				    break;
			case 4: for(int i = 0; i < 10; i++){
						printf("a1[%d] = %d | ",i,a1[i]);
					}	          
					printf("\n ordenado = %d\n-------------------\n",ordenado(a1,10));
					for(int i = 0; i < 10; i++){
						printf("a2[%d] = %d | ",i,a2[i]);
					}	          
					printf("\n ordenado = %d\n-------------------\n",ordenado(a2,10));
					for(int i = 0; i < 10; i++){
						printf("a3[%d] = %d | ",i,a3[i]);
					}	          
					printf("\n ordenado = %d\n-------------------\n",ordenado(a3,10));
					break;
			case 5: merge(b1,10,b2,10,b12r);
					for(int i = 0; i < 20; i++){
						printf("b12r[%d] = %d |\n",i,b12r[i]);
					}
					merge(b3,10,b4,10,b34r);
					for(int i = 0; i < 20; i++){
						printf("b34r[%d] = %d |\n",i,b34r[i]);
					}
					break;
			case 6: printf("\n-------\nANTES\n-------\n");
					for(int i = 0; i < 10; i++){
						printf("c1[%d] = %d |\n",i,c1[i]);
					}
					printf("\n\nExistem %d elementos menores ou iguais a %d\n\n",partition(c1,10,c1t),c1t);
					printf("\n-------\nDEPOIS\n-------\n");
					for(int i = 0; i < 10; i++){
						printf("c1[%d] = %d |\n",i,c1[i]);
					}
					break;
			case 0: printf("\n----------\nTerminando\n----------\n");
					break;
			default: printf("\n----------\nOpção inválida\n----------\n");
					 break;
		}
	}
}