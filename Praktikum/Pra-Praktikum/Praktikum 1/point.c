#include <stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"

/*
 * Mengapa ada yang menggunakan pointer, ampersand, dan asterisk?
 * Menggunakan asterisk untuk mengakses variabel yang akan diubah value-nya, tanpa perlu membuat variabel lainnya.
 * Lalu pada implementasi dari testpoint menggunakan ampersand untuk mengambil alamat dari variabel yang akan diubah valuenya.
 * Ingat bahwa *(&x) = value dari x itu sendiri
 * Dan ingat juga bahwa lokasi dari variabel di main dan di header itu kan beda file, jadi perlu ngasih tau alamatnya dulu.
 * makanya BacaPOINT perlu pakai ampersand, karena fungai BacaPOINT di point.c itu mengambil variabel dari file main, yg mana enggak satu file
 * Tapi TulisPOINT enggak perlu pakai ampersand karena dia cuma ngeprint, enggak ngubah value dari variabelnya dan cuman butuh value dari variabelnya, ibaratnya cuman penghubung, bukan buat ngambil
 */

/*
    The BacaPOINT() function takes a pointer to a POINT variable as its argument. This means that the BacaPOINT() function expects to receive the address of a POINT variable.
    The &p1 in the BacaPOINT() function call tells the compiler to take the address of the p1 variable. This means that the address of the p1 variable is passed to the BacaPOINT() function.
    The CreatePoint() function takes a pointer to a POINT variable as its argument. This means that the CreatePoint() function expects to receive the address of a POINT variable.
    The P in the CreatePoint() function call is a pointer to a POINT variable. This means that the address of the P variable is passed to the CreatePoint() function.
 */

void CreatePoint(POINT *P, float x, float y) {
    Absis(*P) = x;
    Ordinat(*P) = y;
}

void BacaPOINT(POINT *P) {
    float x, y;
    scanf("%f %f", &x, &y);
    CreatePoint(P, x, y);
}

void TulisPOINT(POINT P) {
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2) {
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ(POINT P1, POINT P2) {
    return ((Absis(P1) != Absis(P2)) && Ordinat(P1) != Ordinat(P2));
}

boolean IsOrigin(POINT P) {
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX(POINT P) {
    return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P) {
    return (Absis(P) == 0);
}

int Kuadran(POINT P) {
    if (Absis(P) > 0) {
        if (Ordinat(P) > 0) {
            return 1;
        } else {
            return 4;
        }
    }
    else {
        return (Ordinat(P) > 0) ? 2 : 3;
    }
}

POINT NextX(POINT P) {
    POINT pt;
    CreatePoint(&pt, Absis(P) + 1, Ordinat(P));
    return pt;
}

POINT NextY(POINT P) {
    POINT pt;
    CreatePoint(&pt, Absis(P), Ordinat(P) + 1);
    return pt;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY) {
    POINT pt;
    CreatePoint(&pt, Absis(P) + deltaX, Ordinat(P) + deltaY);
    return pt;
}

POINT MirrorOf(POINT P, boolean SbX) {
    POINT pt;
    if (SbX) {
        CreatePoint(&pt, Absis(P), Ordinat(P) * -1);
    }
    else {
        CreatePoint(&pt, Absis(P) * -1, Ordinat(P));
    }
    return pt;
}

float Jarak0(POINT P) {
    return (sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2)));
}

float Panjang(POINT P1, POINT P2) {
    return (sqrt(pow(Absis(P1) - Absis(P2), 2) + pow(Ordinat(P1) - Ordinat(P2), 2)));
}

void Geser(POINT *P, float deltaX, float deltaY) {
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P) {
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P) {
    Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX) {
    if (SbX) {
        Ordinat(*P) *= -1;
    }
    else {
        Absis(*P) *= -1;
    }
}

void Putar(POINT *P, float Sudut) {
    float x = Absis(*P);
    float y = Ordinat(*P);
    Sudut = Sudut * 3.141592 / 180;
    Absis(*P) = x * cos(Sudut) + y * sin(Sudut);
    Ordinat(*P) = -1 * x * sin(Sudut) + y * cos(Sudut);
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2) {
    int m = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    int c = Ordinat(P1) - m * Absis(P1);
    printf("(%d,%d)", m, c);
}
