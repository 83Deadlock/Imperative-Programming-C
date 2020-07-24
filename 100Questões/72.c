int listToArray (LInt l, int v[], int N) {
	int x = 0, i;
	for (i = 0; l != NULL && N > 0; i++, N--, x++){
		v[i] = l->valor;
		l = l->prox;
	}
	return x;
}
