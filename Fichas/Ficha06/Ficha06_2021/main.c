#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
#include "Queue.h"

int main() {
  int i; 
  //SStack S1 = (struct staticStack*) malloc(sizeof(struct staticStack));
  //DStack D1 = (struct dinStack*) malloc(sizeof(struct dinStack));

  //SQueue Q1 = (struct staticQueue*) malloc(sizeof(struct staticQueue));
  //DQueue R1 = (struct dinQueue*) malloc(sizeof(struct dinQueue));
  
  /*printf ("Testing Stacks .... \n");
  SinitStack (S1);
  if(SisEmpty(S1)) printf("Stack vazia...\n");
  //DinitStack (D1);
  for (i=0; i<15; i++) {
    if (Spush (S1,i) != 0) printf ("ERROR pushing %d\n", i);
    //if (Dpush (D1,i) != 0) printf ("ERROR pushing %d\n", i);
  }

  ShowSStack (S1);
  int x;
  for (i=0; i<15; i++) {
    if (Spop (S1,&x) != 0) printf ("ERROR popping %d\n", i);
    else{
    	printf("\tx = %d && sp = %d\n",x,S1->sp);
    	Stop(S1,&x);
    	printf("\tx = %d && sp = %d\n",x,S1->sp);
    }
    
  }
  //ShowDStack (D1);*/
  
  /*printf ("Testing Queues .... \n");
  SinitQueue (Q1);
  //DinitQueue (R1);
  if(SisEmptyQ(Q1)) printf("Queue vazia...\n");
  for (i=0; i<15; i++) {
    if (Senqueue (Q1,i) != 0) printf ("ERROR enqueueing %d\n", i);
  //  if (Denqueue (R1,i) != 0) printf ("ERROR enqueueing %d\n", i);
  }
  ShowSQueue (Q1);
  int x;
  for (i=0; i<15; i++) {
    if (Sdequeue (Q1,&x) != 0) printf ("ERROR enqueueing %d\n", i);
    else{
    	printf("x = %d\n",x);
    }
  //  if (Denqueue (R1,i) != 0) printf ("ERROR enqueueing %d\n", i);
  }
  ShowSQueue (Q1);
  //ShowDQueue (R1);*/

  return 0;
} 