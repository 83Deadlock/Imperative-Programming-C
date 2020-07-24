int procuraMenor (ABin a, int x) {
	int i;
	if (a == NULL)
		i = 0;
	else if (a->valor < x)
		i = 1;
	else if (procuraMenor (a->esq, x) == 1 || procuraMenor (a->dir, x) == 1)
		i = 1;
	else
		i = 0;
	return i;
}
int procuraMaior (ABin a, int x) {
	int i;
	if (a == NULL)
		i = 0;
	else if (a->valor > x)
		i = 1;
	else if (procuraMaior (a->esq, x) == 1 || procuraMaior (a->dir, x) == 1)
		i = 1;
	else
		i = 0;
	return i;
}
int deProcura (ABin a) {
	int i;
	if (a == NULL)
		i = 1;
	else if (procuraMaior (a->esq, a->valor) == 1 || procuraMenor (a->dir, a->valor) == 1)
		i = 0;
	else if (deProcura (a->esq) == 0 || deProcura (a->dir) == 0)
		i = 0;
	else
		i = 1;
	return i;
}
