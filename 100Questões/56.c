int removeOneOrd (LInt *lista, int x){
    LInt ant, atual;
    
    atual = *lista;
    
    if(atual == NULL)            //0 elementos
        return 1;
        
    if (atual->valor == x) {           //1 elemento
            *lista = NULL;
            return 0;
        }
        
    while(atual->prox != NULL){        // 2+ elementos
        ant = atual;
        atual = atual->prox;
        
        if(atual->valor == x){
            ant->prox = atual->prox;
            return 0;
        }
    }
    return 1;
}
