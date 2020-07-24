int iguaisConsecutivos (char s[]) {
    int i,j; //Variáveis usadas para percorrer o array
    int r = 0; //variável que vai guardar quantas vezes seguidas se verifica um char
    int n = 0; //Variável que guarda o valor máximo de ocorrências
    char c;
    for (i = 0; s[i] != '\0'; i++){ // Percorre o array
        r = 0;
        for (j = i;s[i] == s[j];j++){ // Conta quantas vezes seguidas o char se verifica
            r++;
        }
        if(r > n){ //Verifica se o numero de ocorrências do char é maior do array até esse ponto
            n = r;
            c = s[i];
        }
    }
    return n;
}
