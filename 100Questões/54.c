LInt reverseL (LInt lista) {
	LInt ant = NULL, aux;

	if (lista == NULL)
		return lista;

	while (lista != NULL){
		aux = lista->prox;
		lista->prox = ant;
		ant = lista;
		lista = aux;
	}

	return ant;
}
