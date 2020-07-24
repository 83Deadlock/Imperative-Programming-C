int altura (ABin a) {
	int x;
	if (a == NULL)
		x = 0;
	else {
		if (altura (a->esq) > altura (a->dir))
			x = 1 + altura (a->esq);
		else
			x = 1 + altura (a->dir);
	}
	return x;
}
