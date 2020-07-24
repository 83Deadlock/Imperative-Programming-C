void preorder_aux (ABin a, LInt *l) {
	if (a == NULL) return;
	LInt atual = *l;
	while (atual->prox != NULL)
		atual = atual->prox;
	atual->prox = newLInt (a->valor, NULL);
	preorder_aux (a->esq, l);
	preorder_aux (a->dir, l);
	return;	
}

void preorder (ABin a, LInt *l) {
	*l = newLInt (0, NULL);
	preorder_aux (a, l);
	LInt aux = *l;
	*l = aux->prox;
	free (aux);
	return;
}
