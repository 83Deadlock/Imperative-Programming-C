int freeAB (ABin a) {
	int i;
	if (a == NULL)
		i = 0;
	else {
		i = 1 + freeAB(a->esq) + freeAB(a->dir);
		free (a);
	}
	return i;
}
