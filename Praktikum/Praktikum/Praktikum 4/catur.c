#include <stdalign.h>
#include <stdio.h>
#include "boolean.h"
#include "matrix.h"
// #include "matrix.c"

int main() {
    Matrix m1;
    readMatrix(&m1, 8, 8);
    int i, j, hitam = 0, putih = 0;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            if ((i + j) % 2 == 0 && ELMT(m1, i, j) == 1) {
                hitam++;
            }
            else if ((i + j) % 2 == 1 && ELMT(m1, i, j) == 1) {
                putih++;
            }
        }
    }
    printf("%d %d\n", hitam, putih);
    return 0;
}