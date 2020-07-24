int length (LInt l){
    int c = 0;
    while(l != NULL) {c++; l = l->prox;}
    return c;
}
