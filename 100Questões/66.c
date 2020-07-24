#include tipos.h

//Defina uma fun¸c˜ao int maximo (LInt l) que calcula qual o maior valor armazenado numa
//lista não vazia.

LInt cloneL (LInt l){
  LInt new = NULL;
  LInt ant = NULL;
  if(l == NULL){
        new=NULL;
        return new;
  }
  else{
      while(l != NULL){
          if(ant == NULL){
              new = newLInt(l->valor,NULL);
              ant = new;
              new = new->prox;
              l = l->prox;
          }
          else{
              new = newLInt(l->valor,NULL);
              new = new->prox;
              l = l->prox;
          }
      }
      new = NULL;
      return ant;
  }
}
