#include "boolean.h"
#include "matrix.h"
#include <stdio.h>

Matrix PangkatMatrix(Matrix m, int pangkat) {
    Matrix identity;
    createMatrix(2, 2, &identity);
    ELMT(identity, 0, 0) = 1;
    ELMT(identity, 0, 1) = 0;
    ELMT(identity, 1, 0) = 0;
    ELMT(identity, 1, 1) = 1;

    if (pangkat == 0) {
        return identity;
    }
    else if (pangkat == 1) {
        return m;
    }
    else {
        Matrix m2 = PangkatMatrix(m, pangkat / 2);
        Matrix m3 = multiplyMatrixWithMod(m2, m2, 2003);
        if (pangkat % 2 == 1) {
            m3 = multiplyMatrixWithMod(m3, m, 2003);
        }
        return m3;
    }
}

int main() {
    int k;
    scanf("%d", &k);
    if (k <= 0) {
        printf("0\n");
    }
    else if (k == 1|| k == 2) {
        printf("1\n");
    }
    else {
        Matrix pengali;
        createMatrix(2, 2, &pengali);
        ELMT(pengali, 0, 0) = 1;
        ELMT(pengali, 0, 1) = 1;
        ELMT(pengali, 1, 0) = 1;
        ELMT(pengali, 1, 1) = 0;
        pengali = PangkatMatrix(pengali, k - 2);

        Matrix m;
        createMatrix(2, 1, &m);
        ELMT(m, 0, 0) = 1;
        ELMT(m, 1, 0) = 1;

        Matrix res = multiplyMatrixWithMod(pengali, m, 2003);
        printf("%d\n", ELMT(res, 0, 0));
    }
}