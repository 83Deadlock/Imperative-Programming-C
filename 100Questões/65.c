void concatL (LInt *a, LInt b){
    LInt aux = *a;
    if(aux==NULL){*a = b;}
    else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox =b;
    }
}
