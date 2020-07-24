void posorder_aux (ABin a, LInt *l) {
	if (a == NULL) return;
	posorder_aux (a->esq, l);
	posorder_aux (a->dir, l);
	LInt atual = *l;
	while (atual->prox != NULL)
		atual = atual->prox;
	atual->prox = newLInt (a->valor, NULL);
	return;
}

void posorder (ABin a, LInt *l) {
	*l = newLInt (0, NULL);
	posorder_aux (a, l);
	LInt aux = *l;
	*l = aux->prox;
	free (aux);
	return;
}
