LInt parte (LInt l) {
	if (l == NULL) return l;
	LInt atual = l->prox, ant = l, new = newLInt (0, NULL), auxn = new;
	int i;
	for (i = 2; atual != NULL; i++) {
		if (i % 2 == 0) {
			auxn->prox = atual;
			auxn = auxn->prox;
			ant->prox = atual->prox;
			atual = atual->prox;
			auxn->prox = NULL;
		}
		else {
			ant = ant->prox;
			atual = atual->prox;
		}
	}
	auxn = new;
	new = new->prox;
	free (auxn);
	return new;
}
