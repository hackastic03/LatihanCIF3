#include <stdalign.h>
#include <stdio.h>
#include "boolean.h"
#include "matrix.h"
// #include "matrix.c"


boolean check(Matrix m1, Matrix m2, int a, int b, int n, int m) { // a, b dimensi matriks 2, awal, akhir dimensi matriks 1
    int i, j, k, l;
    int p, t;
    int hasil = 0;
    int count = countElmt(m2);
    for (i = 0; i < n; i++) {

        for (j = 0; j < m; j++) {
        hasil = 0;
        // printf("test\n");
            for (k = i; k < (a + i); k++) {
                for (l = j; l < (b + j); l++) {
                    // printf("%d\n", ELMT(m1, k, l));
                    if (ELMT(m1, k, l) == ELMT(m2, k - i, l - j)) {
                        hasil++;
                        // printf(" hasil %d\n", hasil);
                    }
                }
            }
            if (hasil == count) {
                return true;
            }
        }
    }
    return false;
    
}



int main() {
    int n, m, k, i, a, b, ind, l, it;
    Matrix m1;
    scanf("%d", &n);
    scanf("%d", &m);
    readMatrix(&m1, n, m);
    int hasilcek = 0;

    scanf("%d", &it);
    for (ind = 0; ind < it; ind++) {
        scanf("%d", &a);
        scanf("%d", &b);
        Matrix m2;
        readMatrix(&m2, a, b);

        if (check(m1, m2, a, b, n, m) == true) {
            hasilcek++;
        }
        // printf("Hasil; retrun %d\n", hasilcek);
        
    }
    if (hasilcek == it) {
        printf("Puzzle dapat diselesaikan.\n");
    }
    else {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }
    return 0;
}