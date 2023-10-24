#include <stdalign.h>
#include <stdio.h>
#include "boolean.h"
#include "matrix.h"
// #include "matrix.c"

int luas(int a, int b) {
    return a * b;
}


int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    int l1;
    scanf("%d", &l1);
    int i, j, p, l, luas, maks = 0;
    Matrix m;
    readMatrix(&m, row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            for (p = i; p < row; p++) {
                for (l = j; l < col; l++) {
                    luas = 0;

                    int x, y;
                    for (x = i; x <= p; x++) {
                        for (y = j; y <= l; y++) {
                            luas += ELMT(m, x, y);
                        }
                    }

                    int panjang = p - i + 1;
                    int lebar = l - j + 1;
//                    printf("%d %d %d\n", panjang, lebar, luas);
//                    printf("Indeks: %d %d %d\n", i, j, m.mem[i][j]);

                    if (panjang * lebar == l1 && luas > maks) {
                        maks = luas;
                    }
                }
            }
        }
    }

    printf("%d\n", maks);
    return 0;
}