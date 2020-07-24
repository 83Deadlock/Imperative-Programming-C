int maiorAB (ABin a) {
	while (1) {
		if (a->dir == NULL)
			return a->valor;
		else
			a = a->dir;
	}
}
