void remreps (LInt l) {
	if (l == NULL) return;
	int x = l->valor;
	LInt ant = l, atual = l->prox, aux;
	while (atual != NULL) {
		if (atual->valor == x) {
			aux = atual;
			atual = atual->prox;
			free (aux);
			ant->prox = NULL;
		}
		else {
			x = atual->valor;
			ant->prox = atual;
			ant = ant->prox;
			atual = atual->prox;
		}
	}
	return;
}
