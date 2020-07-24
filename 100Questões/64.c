void appendL (LInt *l, int x){
    LInt aux = *l;
    LInt nodo = newLInt(x,NULL);
    if(aux == NULL) *l = nodo;
    else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = nodo;
    }
}
