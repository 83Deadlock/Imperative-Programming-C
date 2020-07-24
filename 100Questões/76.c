LInt rotateL (LInt l) {
	if (l == NULL) return l;
	LInt atual = l;
	while (atual->prox != NULL)
		atual = atual->prox;
	atual->prox = l;
	atual = l;
	l = l->prox;
	atual->prox = NULL;
	return l;
}
