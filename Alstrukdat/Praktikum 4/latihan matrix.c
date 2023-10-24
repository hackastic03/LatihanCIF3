#include <stdio.h>
#include "../../Pra-Praktikum/Praktikum 4/boolean.h"
#include "../../Pra-Praktikum/Praktikum 4/matrix.c"

Matrix insertRow(Matrix m1, Matrix m2, int n) {
    int i, j;
    Matrix m3;
    createMatrix(ROW_EFF(m1) + 1, COL_EFF(m2), &m3);
    for (i = ROW_EFF(m3) - 1; i > n; i--) {
        for (j = 0; j < COL_EFF(m3); j++) {
            ELMT(m3, i, j) = ELMT(m1, i - 1, j);
        }
    }
    for (j = 0; j < COL_EFF(m3); j++) {
        ELMT(m3, n, j) = ELMT(m2, 0, j);
    }
    return m3;
}

int main() {
    Matrix m1, m2, m3;
    readMatrix(&m1, 3, 3);
    displayMatrix(m1);
    readMatrix(&m2, 1, 3);
    displayMatrix(m2);
    m3 = insertRow(m1, m2, 0);
    displayMatrix(m3);
    printf("%d\n", getLastIdxRow(m3));
    return 0;
}