void nivelL_aux (ABin a, int n, LInt *l) {
	if (a == NULL) return;
	if (n == 1) {
		*l = newLInt (a->valor, *l);
	}
	else {
		nivelL_aux (a->dir, n-1, l);
		nivelL_aux (a->esq, n-1, l);
	}
}

LInt nivelL (ABin a, int n) {
	LInt new = NULL;
	nivelL_aux (a, n, &new);
	return new;
}
