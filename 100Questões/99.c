int quantosMaiores (ABin a, int x) {
	int i = 0;
	if (a != NULL) {
		if (a->valor > x)
			i = 1;
		i += quantosMaiores (a->esq, x) + quantosMaiores (a->dir, x);
	}
	return i;
}
