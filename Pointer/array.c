#include <stdio.h>
#include "../boolean.h"

/* Pada array of integer (int A[]), A sendiri sudah merupakan alamat dari array tersebut, jadi istilahnya A dan &A itu sama2 saja.
 * Untuk mengakses nilainya, bisa digunakan *A seperti untuk mengakses value dari pointer, namun hanya output nilai array indeks 0 saja
 * Untuk mengakses nilai indeks selanjutnya, gunakan aritmetika pointer. Jika array adalah array of integer, maka tiap indeksnya memiliki
 * size 4 byte, sehingga indeks selanjutnya diakses menggunakan *(A + 1), dan alamatnya akan berupa A + 4. Hal ini sama saja dengan mengakses menggunakan indeks array seperti
 * A[i] di mana i adalah indeks dalam array.
 *
 * Untuk array of character, misal char S[], maka S itu sudah menjadi alamat dan value itu sendiri, sehingga untuk mengakses character di
 * array S cukup print("%s", S) jika array of character berupa string, tidak bisa dioperasikan dengan * atau &
 */


int returnAlamat(int a) {
    printf("Alamat variabel a di local returnAlamat adalah %d dan value-nya: %d\n", &a, a);
    return a;
}

/* Lokasi penyimpanan variabel berbeda antara di local maupun di main. Jika ada pemanggilan variabel dari main ke local,
 * hanya value nya saja yang berubah, sementara alamat variabel di fungsi lokal stays di local, dan di main tetap di main
 * alamatnya
 * Jika variabel yang sama digunakan namun hanya diubah value-nya, maka alamatnya tidak akan berubah.
 */

int returnAlamatwithPointer(int *b) {
    printf("Alamat dari variabel *b di local adalah %d\n", b);
    return *b + 10;
}


int main() {
    char S[] = "hello";
    printf("String dari array of character adalah %s \n", S);
    int A[] = {4, 5, 6, 7};
    printf("Alamat bisa diakses menggunakan A: %d atau &A: %d yang merupakan alamat elemen pertama array\n", A, &A);
    printf("Untuk mengakses elemen pertama bisa menggunakan *A: %d atau A[0]: %d\n", *A, A[0]);
    printf("Akses elemen berikutnya menggunakan *(A + 1): %d atau A[1]: %d\n", *(A + 1), A[1]);
    printf("Alamat dari indeks-1 adalah &A[1]: %d atau (A + 1): %d\n\n", &A[1], (A + 1));
    int a = 0;
    printf("Alamat awal variabel a di main adalah: %d dan value-nya: %d\n", &a, a);
    int x = a;
    a = returnAlamat(a);
    printf("Alamat akhir variabel a di main setelah pemanggilan return alamat adalah tetap: %d dan value-nya: %d\n", &a, a);
    printf("Alamat variabel x di mana x = a adalah: %d dan value-nya: %d\n\n", &x, x);

    int b = 12;
    int *p = &b; // p = &b, *p = b
    printf("Alamat dari variabel b di main adalah: %d dan nilainya adalah %d\n", p, *p);
    b = returnAlamatwithPointer(&b); // Karena kita menginputkan alamat, maka alamat variabel yang diproses di local juga sama tanpa perlu membuat variabel dengan alamat baru
    printf("Setelah pemanggilan fungsi, alamat b adalah %d dan nilainya adalah %d\n", &b, b);
    return 0;
}