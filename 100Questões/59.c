LInt parteAmeio (LInt *l) {

	LInt y = newLInt (0,*l), auxl = *l, auxy = y;
	int x;

	for (x = 0; auxl != NULL; x++)
		auxl = auxl->prox;

	auxl = auxy->prox;
	x = x / 2;

	while (x > 0) {
		auxl = auxl->prox;
		auxy = auxy->prox;
		x--;
	}

	auxy->prox = NULL;
	*l = auxl;

	auxy = y;
	y = y->prox;
	free (auxy);

	return y;
}
