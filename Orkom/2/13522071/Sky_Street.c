#include <stdio.h>

int func4(int base, int pow) {
    for (int i = 0; i < pow; i++) {
        base *= base;
    }
    return base;
}

void Sky_Street() {
    int a, b;
    scanf("%d %d", &a, &b);
    int base = 7;
    int pow = 6;
    int res = func4(base, pow);
    if (a == pow - 1 && b == res) {
        return;
    }
    illegal_move();
}