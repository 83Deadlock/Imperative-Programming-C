int encontraMaior (LInt l) {

	if (l == NULL)
		return -1;

	int x = l->valor;

	while (l != NULL) {
		if (l->valor > x)
			x = l->valor;

		l = l->prox;
	}

	return x;
}

int removeMaiorL (LInt *l) {

	LInt atual = *l, ant = newLInt (0, *l);
	int i = 1, x = encontraMaior (*l);

	*l = ant;

	while (atual != NULL && i) {

		if (atual->valor == x) {
			ant->prox = atual->prox;
			free (atual);
			atual = atual->prox;
			i = 0;
		}
		else {
			atual = atual->prox;
			ant = ant->prox;
		}
	}

	atual = *l;
	*l = atual->prox;
	free (atual);

	return x;
}
