#include <stdio.h>

int trailingZ (unsigned int n) {
	int r = 0;
    if (n % 2 == 1) return 0;
    while (n % 2 == 0) {
        n = n / 2;
        r++;
    }
    return r;
}
