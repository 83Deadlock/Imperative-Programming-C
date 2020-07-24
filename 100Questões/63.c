void init (LInt *l) {

	LInt atual = *l, ant = newLInt (0, *l);
	*l = ant;
	while (atual->prox != NULL) {
		atual = atual->prox;
		ant = ant->prox;
	}
	ant->prox = NULL;
	free (atual);
	atual = *l;
	*l = atual->prox;
	free (atual);
}
