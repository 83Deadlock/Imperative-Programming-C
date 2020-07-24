int pruneAB (ABin *a, int l) {
	if (*a == NULL) return 0;
	int x = 0;
	x += pruneAB (&((*a)->esq), l-1);
	x += pruneAB (&((*a)->dir), l-1);
	if (l < 1) {
		free (*a);
		x++;
		*a = NULL;
	}
	else if (l == 1) {
		(*a)->esq = NULL;
		(*a)->dir = NULL;
	}
	return x;
}
