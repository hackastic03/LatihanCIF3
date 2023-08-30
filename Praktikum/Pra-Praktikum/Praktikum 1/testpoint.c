#include <stdio.h>
#include "point.c"

int main() {
    POINT p1, p2; // Deklarasi variabel, yang artinya si variabel udah ada di memori (sudah dialokasikan tapi belum diisi nilainya
    float dx, dy;
    printf("Masukkan titik 1: \n");
    BacaPOINT(&p1); // Yang dimasukkan adalah address dari variabel p1 yang tadi sudah dideklarasikan.
    printf("Titik yang dibaca adalah \n");
    TulisPOINT(p1);
    printf("Masukkan titik 2: \n");
    BacaPOINT(&p2);
    TulisPOINT(p2);
    printf("%d\n", EQ(p1, p2));
    return 0;
}

//  Mengapa menggunakan address dari p1 karena di fungsi BacaPOINT itu membutuhkan address dari variabel p1, karena dia akan mengubah value dari variabel p1
//  tanpa perlu meng-copy nilai variabel tersebut kalau enggak pake pointer (kalau dimasukinnya variabel biasa, bukan addressnya, maka yang diubah adalah variabel lokal
//  di fungsi BacaPOINT, bukan variabel p1 di main) . Selain itu, fungsi BacaPOINT juga menerima input hanya berupa pointer (BacaPOINT(*P)) dan bukan variabel biasa.
//  Jadi, kalau mau memasukkan variabel biasa, harus diambil addressnya dulu, baru dimasukkan ke fungsi BacaPOINT.
// Ingat kembali juga kalau variabel p1 p2 di main itu berbeda file dengan fungsi yg memprosesnya, yaitu di point.c, jadi perlu diambil addressnya dulu yg bisa diakses
// oleh fungsi BacaPOINT di point.c
// Lalu mengapa di fungsi CreatePOINT yang ada di BacaPOINT itu tidak menggunakan asterisk seperti di fungsi CreatePOINT yang ada di point.c?
// Seperti yang kita tau, kalau ada variabel *x, maka x itu adalah address-nya, dan menggunakan * untuk mengakses value dari alamat tersebut.
//  Kalau di fungsi CreatePOINT yang ada di BacaPOINT itu, variabel P itu adalah address dari variabel p1, jadi kalau mau mengakses value dari variabel p1, tinggal
// menggunakan *P, karena P itu adalah address dari p1, dan *P itu adalah value dari address tersebut, yaitu p1.
// INtinya kalau fungsi expect pointer, kasih dia address dari variabelnya. Asterisk itu bakal ngambil value dari address tersebut.