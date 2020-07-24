int qDig (int n) {
    int r = 0;
    while (n != 0){
        n /= 10;
        ++r;
    }
    return r;
}
