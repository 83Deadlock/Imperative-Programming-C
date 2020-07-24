void removeAux (int x, LInt *l, int *i) {

	LInt atual = *l, ant = newLInt (0, *l);
	int flag = 0;
	*l = ant;

	while (atual != NULL) {

		if (atual->valor == x) {
			if (flag == 0)
				flag = 1;
			else {
				(*i) ++;
				ant->prox = atual->prox;
				free (atual);
				atual = ant->prox;
			}
		}

		atual = atual->prox;
		ant = ant->prox;
	}

	atual = *l;
	*l = atual->prox;
	free (atual);
}

int removeDups (LInt *l) {

	LInt atual = *l;
	int i = 0;

	while (atual != NULL) {
		removeAux (atual->valor, l, &i);
		atual = atual->prox;
	}

	return i;
}
