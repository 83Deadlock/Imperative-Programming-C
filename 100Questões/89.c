void nivelV_aux (ABin a, int n, int v[], int *x) {
	if (a == NULL) return;
	if (n == 1) {
		v[*x] = a->valor;
		(*x)++;
	}
	else {
		nivelV_aux (a->esq, n-1, v, x);
		nivelV_aux (a->dir, n-1, v, x);		
	}

}

int nivelV (ABin a, int n, int v[]) {
	int x = 0;
	nivelV_aux (a, n, v, &x);
	return x;
}
