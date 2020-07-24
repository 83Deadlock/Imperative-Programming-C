LInt arrayToList (int v[], int N){
    LInt top = NULL, ant, atual;
    int i;
    for (i = 0; i < N; i++) {
        if (i == 0) {
            atual = malloc (sizeof(LInt));
            top = atual;
            atual->valor = v[i];
            atual->prox = NULL;
        }
        else {
            ant = atual;
            atual = malloc (sizeof(LInt));
            atual->valor = v[i];
            ant->prox = atual;
            atual->prox = NULL;
        }
    }
    return top;
}
