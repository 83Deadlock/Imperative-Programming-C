void freeL (Lint lista) {
	LInt aux;

	if (lista == NULL)
		return;

	while (lista != NULL){
		aux = lista;
		lista = lista->prox;
		free(aux);
	}
}
