void insertOrd (LInt * lista, int x) {

	LInt nodo = malloc (sizeof(LInt));
	LInt aux = (*lista);
	LInt ant;

	nodo->valor = x;
	nodo->prox = NULL;
	// 0 elementos
	if ((*lista) == NULL) {
		(*lista) = nodo;
		return;
	}
	// 1 elemento
	if (aux->prox == NULL) {
		if (x < aux->valor) {
			(*lista) = nodo;
			nodo->prox = aux;
		}
		else {
			aux->prox = nodo;
		}
		return;
	}
	
	ant = aux; // 2 ou mais elementos
	aux = aux->prox;

	if (ant->valor > x) {
		(*lista) = nodo;
		nodo->prox = ant;
		return;
	}
	else {

		while (aux->valor < x) {
			if (aux->prox == NULL) {
				aux->prox = nodo;
				return;
			}
			else {
				ant = ant->prox;
				aux = aux->prox;
			}
		}

		ant->prox = nodo;
		nodo->prox = aux;
		return;
	}

}
