void removeMaiorA_aux (ABin *atual, ABin *ant) {
    ABin aux = NULL;
	if ((*atual)->dir == NULL) {
	    aux = *atual;
		(*ant)->dir = (*atual)->esq;
		free (aux);
	}
	else {
		removeMaiorA_aux (&(*atual)->dir, atual);
	}
}
void removeMaiorA (ABin *a) {
	ABin aux = NULL;
	if (*a == NULL) return;
	else if ((*a)->dir == NULL) {
		aux = *a;
		*a = (*a)->esq;
		free (aux);
		return;
	}
	removeMaiorA_aux (&(*a)->dir, a);
	return;
}
