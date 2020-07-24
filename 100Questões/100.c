int length (LInt l) {
	int x = 0;
	while (l != NULL) {
		l = l->prox;
		x++;
	}
	return x;
}

LInt parteAMeio (LInt *l) {
	LInt atual = *l, ant = newLInt (0, atual);
	*l = ant;
	int x = length (atual) / 2;
	while (x > 1) {
		atual = atual->prox;
		ant = ant->prox;
		x--;
	}
	ant->prox = NULL;
	ant = *l;
	*l = ant->prox;
	free (ant);
	return atual;
}

void listToBTree (LInt l, ABin *a) {
	if (l == NULL) {
		*a = NULL;
		return;
	}
	LInt dir = parteAMeio (&l);
	*a = newABin (dir->valor, NULL, NULL);
	listToBTree (l, &(*a)->esq);
	listToBTree (dir->prox, &(*a)->dir);
	return;
}
