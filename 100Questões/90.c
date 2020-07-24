int dumpAbin_aux (ABin a, int v[], int *N, int *i) {
	if (a == NULL) return 0;
	int x = 0;
	x += dumpAbin_aux (a->esq, v, N, i);
	if (*N > 0) {
		v[*i] = a->valor;
		(*i)++;
		(*N)--;
		x++;
	}
	x += dumpAbin_aux (a->dir, v, N, i);
	return x;
}

int dumpAbin (ABin a, int v[], int N) {
	int i = 0, x;
	x = dumpAbin_aux (a, v, &N, &i);
	return x;
}
