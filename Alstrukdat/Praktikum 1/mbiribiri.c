#include <stdio.h>
#include <math.h>
#include "point.h"
#include "garis.h"

int main() {
    int b, n, i, count;
    GARIS g1;
    count = 0;
    scanf("%d", &b);
    BacaGARIS(&g1);
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
       POINT P;
       BacaPOINT(&P);
       if (JarakGARIS(g1, P) <= b) {
        count += 1;
       }
    }
    printf("%d\n", count);
    return 0;
}