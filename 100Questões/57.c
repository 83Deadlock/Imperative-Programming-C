void merge (LInt *r, LInt a, LInt b) {

	LInt atual = newLInt (0, NULL);
	*r = atual;

	while (a != NULL && b != NULL) {

		if (a->valor < b->valor) {
			atual->prox = a;
			a = a->prox;
		}
		else {
			atual->prox = b;
			b = b->prox;
		}

		atual = atual->prox;
	}

	if (a == NULL)
		atual->prox = b;
	else
		atual->prox = a;

	atual = *r;
	*r = atual->prox;
	free (atual);

	return;
}
