#include <stdio.h>
#include "test2.h"
#include "fungsi1.c"

int main() {
    waktu waktusiBoy = {"Boy William", 10, 30};
    printf("%s adalah pemilik jam pertama, dan jamnya menunjukkan pukul %d.%d\n", waktusiBoy.pemilikJam, waktusiBoy.jam, waktusiBoy.menit);
    printf("Volume tabung dengan jari-jari 10 dan tinggi 20 adalah %d\n", volumeTabung(10, 20));
    point p1 = {10, 20};
    printf("Titik yang dimasukkan adalah (%.2f, %.2f)\n", p1.x, p1.y);
    point p2;
    printf("Masukkan nilai x dan y untuk titik kedua: (pisahkan dengan koma):");
    scanf("%f %f", &p2.x, &p2.y);
    if (checkOrigin(p2.x, p2.y)) {
        printf("Koordinat kedua ada di titik asal\n");
    }
    else {
        printf("Koordinat kedua tidak ada di titik asal\n");
    }
}
