int lookupAB (ABin a, int x) {
	int i = 0;
	while (a != NULL && i == 0) {
		if (x == a->valor)
			i = 1;
		else if (x > a->valor)
			a = a->dir;
		else
			a = a->esq;
	}
	return i;
}
