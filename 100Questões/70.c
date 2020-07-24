int drop (int n, LInt *l) {
	LInt ant = newLInt (0, *l);
	*l = ant;
	int x = 0;
	LInt atual = ant->prox, aux = NULL;
	while (atual != NULL && n > 0) {
		ant->prox = atual->prox;
		aux = atual;
		atual = atual->prox;
		free (aux);
		n--;
		x++;
	}
	atual = *l;
	*l = atual->prox;
	free (atual);
	return x;
}
