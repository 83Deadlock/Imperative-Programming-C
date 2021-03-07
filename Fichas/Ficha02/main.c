#include <stdio.h>

//Esta ficha tem os mecanismos de resolução no enunciado de forma mais detalhada

float multInt1(int n, float m){
	float r = 0;
	while(n != 0){
		r += m;
		if(n < 0){
			n++;
		} else {
			n--;
		}
	}
}

float multInt2(int n, float m){
	float r = 0;
	while(n != 0){
		if(n % 2 == 1){
			r+= m;
		}
		n /= 2;
		m *= 2;
	}
	return r;
}

int mdc1 (int a, int b){
	int i;
	if(a < b){
		i = a;
	} else {
		i = b;
	}

	while((b % i != 0 || a % i != 0) && i != 0){
			i--;
	}
	if(i == 0) i = -1;
	return i;
}

int mdc2 (int a, int b){
	int r = -1;

	if(a > b){
		r = mdc2(a-b,b); 
	} else if (a < b){
		r = mdc2(a,b-a);
	} else {
		r = a;
	}

	return r;
}

int mdc3 (int a, int b){
	int r = -1;

	if(a > b){
		r = mdc2(a%b,b); 
	} else if (a < b){
		r = mdc2(a,b%a);
	} else {
		r = a;
	}

	return r;
}

int fib1(int n){
    int f;
    if(n < 3){
        f = 1;
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

void main(){
	int p = -1;
	
	while(p != 0){
		printf("1.- Multiplicação de n por m\n");
		printf("2.- Multiplicação usando a representação binária\n");
		printf("3.- MDC iterativo\n");
		printf("4.- MDC Euclides\n");
		printf("5.- MDC mais eficiente\n");
		printf("0.- Sair\n");
		printf("Pergunta a executar: ");
		scanf("%d",&p);
		switch(p){
			case 1:	printf("Insira o valor de m (float): ");
					float m1;
					scanf("%f",&m1);
					printf("Insira o valor de n (inteiro): ");
					int n1;
					scanf("%d",&n1);
					float r1 = multInt1(n1,m1);
					printf("\n\n %.2f * %d = %.2f \n\n",m1,n1,r1);
					break;

			case 2: printf("Insira o valor de m (float): ");
					float m2;
					scanf("%f",&m2);
					printf("Insira o valor de n (int): ");
					int n2;
					scanf("%d",&n2);
					float r2 = multInt2(n2,m2);
					printf("\n\n %.2f * %d = %.2f \n\n",m2,n2,r2);
					break;

			case 3: printf("Insira o valor de a: ");
					int a3;
					scanf("%d",&a3);
					printf("Insira o valor de b: ");
					int b3;
					scanf("%d",&b3);
					int r3 = mdc1(a3,b3);
					printf("\n\n mdc(%d,%d) = %d \n\n",a3,b3,r3);
					break;

			case 4: printf("Insira o valor de a: ");
					int a4;
					scanf("%d",&a4);
					printf("Insira o valor de b: ");
					int b4;
					scanf("%d",&b4);
					int r4 = mdc2(a4,b4);
					printf("\n\n mdc(%d,%d) = %d \n\n",a4,b4,r4);
					break;

			case 5: printf("Insira o valor de a: ");
					int a5;
					scanf("%d",&a5);
					printf("Insira o valor de b: ");
					int b5;
					scanf("%d",&b5);
					int r5 = mdc3(a5,b5);
					printf("\n\n mdc(%d,%d) = %d \n\n",a5,b5,r5);
					break;		
					
			case 0: printf("Exiting\n");
					break;

			default: printf("Opção inválida\n");
					 break;				

		}
	}
	printf("Saíndo do programa!\n");
}