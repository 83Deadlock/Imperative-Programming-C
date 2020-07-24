ABin cloneMirror (ABin a) {
	if (a == NULL) return NULL;
	ABin new = malloc (sizeof(struct nodo));
	new->valor = a->valor;
	new->esq = cloneMirror (a->dir);
	new->dir = cloneMirror (a->esq);
	return new;
}
