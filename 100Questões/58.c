void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
	LInt atual = l;

	*mx = newLInt(0, NULL);
	LInt mxa = *mx;

	*Mx = newLInt(0, NULL);
	LInt Mxa = *Mx;

	while (atual != NULL) {

		if (atual->valor < x) {
			mxa->prox = atual;
			atual = atual->prox;
			mxa = mxa->prox;
			mxa->prox = NULL;
		}
		else {
			Mxa->prox = atual;
			atual = atual->prox;
			Mxa = Mxa->prox;
			Mxa->prox = NULL;
		}
	}

	atual = *mx;
	*mx = (*mx)->prox;
	free (atual);

	atual = *Mx;
	*Mx = (*Mx)->prox;
	free (atual);

}
