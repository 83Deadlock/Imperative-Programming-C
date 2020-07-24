ABin cloneAB (ABin a) {
	ABin novo;
	if (a == NULL)
		novo = NULL;
	else {
		novo = newABin(a->valor, cloneAB(a->esq), cloneAB(a->dir));		
	}
	return novo;
}
