#include <stdalign.h>
#include <stdio.h>
#include "boolean.h"
#include "matrix.h"
// #include "matrix.c"




int main() {
    int m, n, kali;
    Matrix m1;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &kali);
    readMatrix(&m1, n, m);
    int sum = 0;
    int i, j, k, l, p, t, max = 0, a, b;
    for (i = 0; i < n; i++) {
        t = 0;
        for (l = i; l < (n - i); l++) {
            t++;
            for (j = 0; j < m; j++) {
                p = 0;
                for (k = j; k < (m - j); k++) {
                    p++;
                    if (t * p == kali) {
                        sum = 0;
                        for (a = i; a < l; a++) {
                            for (b = j; b < k; b++) {
                                sum += ELMT(m1, a, b);
                            }
                        }
                        if (sum > max) {
                            max = sum;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", max);
    return 0;
}