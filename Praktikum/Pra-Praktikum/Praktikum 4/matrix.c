#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m) {
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j) {
    return (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m) {
    return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m) {
    return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    return (i < ROW_EFF(m) && i >= 0) && (j < COL_EFF(m) && j >= 0);
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut) {
    int i, j;
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (i = 0; i < ROW_EFF(mIn); i++) {
        for (j = 0; j < COL_EFF(mIn); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }

    }
}

void readMatrix(Matrix *m, int nRow, int nCol) {
    int i, j;
    createMatrix(nRow, nCol, m);
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m) - 1; j++) {
            printf("%d ", ELMT(m, i, j));
        }
        printf("%d", ELMT(m, i, COL_EFF(m) - 1));
        printf("\n");

    }
}

Matrix addMatrix(Matrix m1, Matrix m2) {
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m3;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m3;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) { // (m x p) . (p x n) = m x n
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    int i, j, k;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m2); j++) {
            ELMT(m3, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++) {
                ELMT(m3, i, j) += ELMT(m1, i , k) * ELMT(m2, k, j);
            }
        }
    }
    return m3;
}

Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod) {
    Matrix m4;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m4);
    m4 = multiplyMatrix(m1, m2);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m2); j++) {
            ELMT(m4, i, j) = ELMT(m4, i, j) % mod;
        }
    }
    return m4;
}

Matrix multiplyByConst(Matrix m, ElType x) {
    Matrix m1;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(m1, i, j) = ELMT(m, i, j) * x;
        }
    }
    return m1;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) = ELMT(*m, i, j) * k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2) {
    if (!isMatrixSizeEqual(m1, m2) || countElmt(m1) != countElmt(m2)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                return false;
            }
        }
    }
    return true;

}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    return (!isMatrixEqual(m1, m2));
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return (ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2));

}

int countElmt(Matrix m) {
    return ROW_EFF(m) * COL_EFF(m);
}

boolean isSquare(Matrix m) {
    return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m) {
    if (!isSquare(m)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m);i++) {
        for (j = 0; j < COL_EFF(m);j++) {
            if (ELMT(m, i, j) != ELMT(m, j, i)) {
                return false;
            }
        }
    }
    return true;
}


boolean isIdentity(Matrix m) {
    if (!isSquare(m)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (i == j) {
                if (ELMT(m, i, j) !=1 ) {
                    return false;
                }
            }
            else {
                if (ELMT(m, i, j) != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}


boolean isSparse(Matrix m) {
    int i, j, count = 0;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0) {
                count++;
            }
        }
    }
    return count <= (ROW_EFF(m) * COL_EFF(m) * 5 / 100);
}


Matrix negation(Matrix m) {
    Matrix m1;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(m1, i, j) = ELMT(m, i, j) * (-1);
        }
    }
    return m1;
}

void pNegation(Matrix *m) {
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) *= (-1);
        }
    }
}


float determinant(Matrix m) {
    if (!isSquare(m)){
        return 0;
    }
    int n = getLastIdxRow(m) + 1;
    int tmpRow[11];
    int i, j, k, idx, temp1, temp2;
    int det = 1;
    int co = 1;
    for(i = 0; i < n; i++){
        idx = i;
        while(ELMT(m,idx,i) == 0 && idx < n){
            idx++;
        }
        if (idx == n){
            return 0;
        }
        if (i != idx){
            for(j = 0; j < n; j++){
                temp1 = ELMT(m,i,j);
                ELMT(m,i,j) = ELMT(m,idx,j);
                ELMT(m,idx,j) = temp1;
            }
            det *= -1;
        }
        for(j = 0;j<n;j++){
            tmpRow[j] = ELMT(m,i,j);
        }
        for (j=i+1; j<n; j++){
            temp1 = tmpRow[i];
            temp2 = ELMT(m,j,i);
            for(k=0;k<n;k++){
                ELMT(m,j,k) = ((temp1 * ELMT(m,j,k)) - (temp2 * tmpRow[k]));
            }
            co *= temp1;
        }
    }
    for(i=0;i<n;i++){
        det *= ELMT(m,i,i);
    }
    return det/co;
}



Matrix transpose(Matrix m) {
    Matrix m1;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(m1, i, j) = ELMT(m, j, i);
        }
    }
    return m1;
}

void pTranspose(Matrix *m) {
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = i + 1; j < COL_EFF(*m); j++) {
            int temp = ELMT(*m, i, j);
            ELMT(*m, i, j) = ELMT(*m, j, i);
            ELMT(*m, j, i) = temp;
        }
    }
}


int main() {
    Matrix m;
    readMatrix(&m, 4, 3);
    displayMatrix(m);
    displayMatrix(transpose(m));
    printf("test");
    printf("%f", determinant(m));
    return 0;
}