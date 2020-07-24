LInt NForward (LInt l, int N) {
	if (l == NULL) return NULL;
	while (N > 0) {
		l = l->prox;
		N--;
	}
	return l;
}
