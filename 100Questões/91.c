int somaABin (ABin a) {
	int x;
	if (a == NULL)
		x = 0;
	else
		x = a->valor + somaABin (a->esq) + somaABin (a->dir);
	return x;
}

ABin somasAcA (ABin a) {
	ABin new;
	if (a == NULL) return NULL;
	new = malloc (sizeof(struct nodo));
	new->valor = somaABin (a);
	new->esq = somasAcA (a->esq);
	new->dir = somasAcA (a->dir);
	return new;
}
