#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*) malloc(sizeof(int) * 12);
    // Variabel p menyimpan alamat dari malloc. Data yang dialokasikan malloc berada di heap memory, karena malloc akan return alamat dari heap
    // memory yang sudah dialokasikan. Sebelum malloc di-specify tipe data yang akan ada di data yang dialokasikan, dan memakai * karena yang merupakan
    // tipe data integer adalah isi dari data yang dialokasikan tersebut (untuk dereference nilai yang ada di heap memory)
    printf("Alamat malloc pertama adalah %d\n", p);
    for (int i = 0; i < 12; i++) {
        p[i] = i * i;
        // Cara pengaksesan data di dalam data yang dialokasikan sama dengan array
        printf("%d : %d\n", i, p[i]);
        printf("%d: %d\n", i, &p[i]);
    }
    free(p);
    p = (int*) malloc(sizeof(int) * 5); // Perbedaan malloc dan calloc adalah calloc menggunakan 2 input (banyak data, ukuran sizeof tipedata),
    // dan juga calloc menginisialisasi memory dengan nilai default 0
    printf("Alamat baru dari pointer setelah free adalah %d\n", p);
    for (int i = 0; i < 5; i++) {
        p[i] = i * i * i;
        printf("%d : %d\n", i, p[i]);
        printf("%d: %d\n", i, &p[i]);
    }
    int *r = (int*) realloc(p, 5 * sizeof(int)); // realloc bisa mengubah ukuran alokasi memori, tanpa perlu membuat alokasi baru
    free(p);
    p = NULL; // Agar pointer-nya tidak mengarah kemanapun, totally deallocated
    for (int i = 0; i < 5; i++) {
        printf("Nilai: %d alamat: %d\n", r[i], &r[i]);
    }
    return 0;
}