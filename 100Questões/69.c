int take (int n, LInt *l) {
	LInt ant = newLInt (0, *l);
	*l = ant;
	int x = 0;
	LInt atual = ant->prox;
	while (atual != NULL && n > 0) {
		ant = ant->prox;
		atual = atual->prox;
		n--;
		x++;
	}
	if (n == 0) {
		ant->prox = NULL;
		while (atual != NULL) {
			ant = atual;
			atual = atual->prox;
			free (ant);
		}
	}
	atual = *l;
	*l = atual->prox;
	free (atual);
	return x;
}
