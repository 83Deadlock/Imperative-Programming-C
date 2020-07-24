void imprimeL (LInt lista) {

	while (lista != NULL){
		printf("%d\n", lista->valor);
		lista = lista->prox;
	}
}
