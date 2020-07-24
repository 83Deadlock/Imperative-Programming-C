int depthOrd (ABin a, int x) {
	int i = 1;
	while (a != NULL) {
		if (x == a->valor)
			return i;
		else if (x > a->valor) {
			a = a->dir;
			i++;
		}
		else {
			a = a->esq;
			i++;
		}
	}
	return -1;
}
