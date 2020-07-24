#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100
typedef struct stack {
    int sp;
    int valores[MAX];
} STACK;

void initStack(STACK *s){
    s->sp = 0;
}

int isEmptyS (STACK *s){
    int r = 0;
    if(s->sp == 0) {r = 1;}
    return r;
}

int push (STACK *s, int x){
    int r = 1;
    if(s->sp < MAX){
        s->valores[s->sp] = x;
        s->sp++;
        r = 0;
    }
    return r;
}

int pop (STACK *s, int *x){
    int r = 1;
    if(!isEmptyS(s)) {
        *x = s->valores[s->sp-1];
        s->sp--;
        r = 0;
    }
    return r;
}

int top (STACK *s, int *x){
    int r = 1;
    if(!isEmptyS(s)) {
        *x = s->valores[s->sp-1];
        r = 0;
    }
    return r;
}

int minusculas(char s[]){
    int size = strlen(s);
    int subs = 0;
    for(int i = 0; i < size; i++){
        if(!isupper(s[i]) && isalpha(s[i])){
            s[i] = s[i] - 32;
            subs++;
        }
    }
    return subs;
}

int contalinhas (char s[]){
    int size = strlen(s);
    int l = 1;
    for(int i = 0; i < size; i++){
        if(s[i] == '\n') l++;
    }
    return l;
}

int contaPal(char s[]){
    int size = strlen(s);
    int w = 1;
    if(size == 0){
        return 0;
    }
    if(isspace(s[0])){
        w = -1;
    }
    int i = 0;
    for(i; i < size; i++){
        if(isspace(s[i])){
            w++;
            i++;
            while(isspace(s[i])){i++;}
        }
    }
    if(isspace(s[i-1])) w--;
    return w;
}

int procura (char *p, char *ps[], int N){
    for(int i = 0; i < N; i++){
        if(strcmp(p,ps[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int main() {
    int opcao;
    printf("Pergunta: ");
    scanf("%d",&opcao);

    //Pergunta 1
    char string1[] = "Ola Mundo!";
    int subs = 0;

    //Pergunta 2
    char string2[] = "Ola \n Mundo \n Outra \n Vez.";
    int lines = 0;

    //Pergunta 3
    char string3[] = "Ola Mundo Outra Vez.";
    char string31[] = "Ola   Mundo";
    char string32[] = " Ola Mundo ";
    int words = 0;

    //Pergunta 4
    char string4[] = "83Deadlock";
    char string41[] = "AP";
    char *strArray[] = {"4Breeze", "5Shrek", "6Hunter", "9Campista", "13McGregor",
                            "14Rufus", "24Krabs", "29Medium", "30Massas", "35Vader",
                            "43Clock", "44Mozart", "46Siri", "50DiPincello", "51Homeless",
                            "53Persa", "55Luffy", "56Aang", "61Mime", "64Leeroy",
                            "66Baco", "71Toy", "76Slayer", "80Hefner", "83Deadlock",
                            "85Pedras", "86Gumball", "90Baljeet", "95Adamastor", "101Limpinho",
                            "108Muttley", "109Pombo", "111Bond", "120Django", "121Wolf",
                            "124Drácula", "131Woody", "133Bayard", "136Skill", "137Tourette",
                            "139Deejay", "141Hashdrubal", "150Pocahontas", "152Sonic", "154Nacho",
                            "158Bubbles", "165Tripz"};
    int found = -1;

    //Pergunta 5
    STACK *s = malloc(sizeof(struct stack));
    int keep = 1;

    switch(opcao){
        case 1: puts(string1);
                subs = minusculas(string1);
                printf("%d substituições.\n",subs);
                puts(string1);

                break;

        case 2: puts(string2);
                lines = contalinhas(string2);
                printf("%d linhas.\n",lines);

                break;

        case 3: puts(string3);
                words = contaPal(string3);
                printf("%d palavras.\n",words);

                puts(string31);
                words = contaPal(string31);
                printf("%d palavras.\n",words);

                puts(string32);
                words = contaPal(string32);
                printf("%d palavras.\n",words);

                break;

        case 4: found = procura(string4,strArray,47);
                if(found == 0){
                    printf("Não encontrou %s.\n",string4);
                } else if (found == 1){
                    printf("Encontrou %s.\n",string4);
                } else {
                    printf("Colou o pisto.\n");
                }

                found = procura(string41,strArray,47);
                if(found == 0){
                    printf("Não encontrou %s.\n",string41);
                } else if (found == 1){
                    printf("Encontrou %s.\n",string41);
                } else {
                    printf("Colou o pisto.\n");
                }

                break;

        case 5: initStack(s);
                while(keep){
                    puts("1 - initStack\n2 - isEmpty\n3 - push\n4 - pop\n5 - top");
                    int opt;
                    scanf("%d",&opt);
                    int x;
                    switch(opt){
                        case 1 : initStack(s);

                                 break;

                        case 2 : if(isEmptyS(s) == 1){
                                    puts("Stack vazia.\n");
                                } else {
                                    puts("Stack não-vazia.\n");
                                }

                                break;

                        case 3 : printf("Valor a acrescentar: ");
                                 scanf("%d",&x);
                                 if(push(s,x) == 0){
                                     printf("Success\n");
                                 } else {
                                     printf("Insuccess\n");
                                 }

                                 break;

                        case 4 : if(pop(s,&x)){
                                    printf("Stack vazia!\n");
                                 } else {
                                    printf("Retirou %d da stack.\n",x);
                                 }

                                break;

                        case 5 : if(top(s,&x)){
                                    printf("Stack vazia!\n");
                                } else {
                                    printf("topo da stack = %d.\n",x);
                                }
                                break;

                        case 6 : printf("sp = %d\n", (s->sp));
                                 break;

                        default : puts("wtf");
                                  keep = 0;
                                  break;
                    }
                }

                break;

        default: printf("Saíndo\n");

                 break;
    }

    return 0;
}
