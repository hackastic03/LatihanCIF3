//#include <stdlib.h>
#include <stdio.h>
#include "test1.h"

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
}