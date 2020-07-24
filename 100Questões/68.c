int maximo (LInt l){
    int max = l->valor;
    if(l->prox == NULL) return max;
    while(l != NULL){
        if(max < l->valor) max = l->valor;
        l = l->prox;
    }
    return max;
}
