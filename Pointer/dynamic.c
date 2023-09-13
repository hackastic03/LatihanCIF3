#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*) malloc(sizeof(int) * 12);
    // Variabel p menyimpan alamat dari malloc. Data yang dialokasikan malloc berada di heap memory
    // Sebelum malloc di-specify tipe data yang akan ada di data yang dialokasikan, dan memakai * karena yang merupakan
    // tipe data integer adalah isi dari data yang dialokasikan tersebut
    printf("%d\n", p);
    for (int i = 0; i < 12; i++) {
        p[i] = i * i;
        // Cara pengaksesan data di dalam data yang dialokasikan mirip dengan array
        printf("%d : %d\n", i, p[i]);
        printf("%d: %d\n", i, &p[i]);
    }
    return 0;
}