int iguaisAB (ABin a, ABin b) {
    int x;
	if (a == NULL && b == NULL)
		x = 1;
	else if (a == NULL || b == NULL)
		x = 0;
	else {
		if (a->valor == b->valor) {
			if (iguaisAB (a->esq, b->esq) == 0 || iguaisAB (a->dir, b->dir) == 0)
				x = 0;
			else
				x = 1;
		}
		else
			x = 0;
	}
	return x;
}
