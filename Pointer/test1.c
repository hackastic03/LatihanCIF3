//#include <stdlib.h>
#include <stdio.h>
#include "test1.h"
#include <stdlib.h>

int pangkat(int a, int b);

int main() {
    int a = 0;
    int *p = &a;
    char *string;
    string = "Hello World!";
    double b; // Untuk float, format specifier adalah %f
    const double pi = 3.14;
    printf("Masukkan angka:");
    scanf("%lf", &b);
    printf("Angka yang dimasukkan adalah %f dan yang sudah ada sebelumnya adalah %d, lalu nilai pi adalah %lf\n", b, a, pi);
    printf("Alamat dari variabel a adalah %p dan nilainya adalah %d \n", p, *p);
    printf("String yang ada adalah %s, di mana itu adalah alamatnya, sementara nilainya adalah default di situ \n", string);
    printf("Hasil dari differenceTimesTwo adalah %d\n", differenceTimesTwo(10, 5));
    int x = 12;
    int *pointer1, **pointer2;
    pointer1 = &x;
    pointer2 = &pointer1;
    printf("Nilai dari variabel x yang diakses dari variabel x: %d; variabel pointer 1: %d; variabel pointer 2: %d\n",
           x, *pointer1, **pointer2);
    printf("Alamat dari variabel x adalah %p; variabel pointer 1: %p; variabel pointer 2: %p\n",
           &x, pointer1, *pointer2);
    printf("Alamat dari variabel pointer 1 adalah %p dari pointer 1; variabel pointer 2: %p\n",
           &pointer1, pointer2);
    printf("Untuk mengakses variabel dari alamat bisa menggunakan *(&x) atau *pointer1 atau **pointer2, misal dengan menggunakan *(&x): %d\n", *(&x));
    char *pointer3;
    pointer3 = NULL;
    // Kenapa array menggunakan pointer? Karena array itu adalah pointer ke elemen pertama dari array tersebut, dan otomatis *array adalah values dari dalam array tersebut

    int *array; // Mengapa int diassign ke *array? Karena array itu adalah pointer ke elemen pertama dari array tersebut, dan otomatis *array adalah
    // values dari dalam array tersebut. Kalau mau mengakses alamat dari array tersebut, tinggal masukin alamatnya.
    int sizeArray;
    printf("Masukkan ukuran array: ");
    scanf("%d", &sizeArray);
    array = (int *) malloc(sizeArray * sizeof(int));
    for(int i = 0; i < sizeArray; i++) {
        array[i] = i*i; // Yang diakses adalah alamat dari array, bukan value dari array. Dari sana baru diakses value tiap elemennya
    }
    for (int i = 0; i < sizeArray; i++) {
        printf("Nilai dari array %d adalah %d\n", i, array[i]);
        printf("Alamat dari array %d adalah %p\n", i, &array[i]);
    }
    free(array);
    int array2[3];
    for (int i = 0; i < 3; i++) {
        array2[i] = i*i;
    }
    for (int i = 0; i < 3; i++) {
        printf("Nilai dari array2 %d adalah %d\n", i, array2[i]);
    }
    // Perbedaan utama dari array statis dan dinamis adalah saat deklarasi, array statis harus langsung diisi ukurannya
    // sedangkan array dinamis tidak diberi ukurannya. Oleh karena itu, dia menggunakan int *array yang artinya *array adalah value-nya, dan array
    // adalah alamatnya.
}