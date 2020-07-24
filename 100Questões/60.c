int removeAll (LInt *l, int x) {

	LInt actual = *l, ant  = newLInt (0,*l), aux;
	int i = 0;
	*l = ant;

	while (actual != NULL) {
		if (actual->valor == x) {
			i ++;
			ant->prox = actual->prox;
			aux = actual;
			actual = actual->prox;
			free (aux);
		}
		else {
		actual = actual->prox;
		ant = ant->prox;			
		}

	}

	aux = *l;
	*l = aux->prox;
	free (aux);

	return i;
}
