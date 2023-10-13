#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"
//#include "liststatik.c"


int findfirst(ListStatik l1, ListStatik l2, int n) {
    int num = -1, i, sum = 0;
    for (i = listLength(l1) - 1; i >= 0; i--) {
        if (ELMT(l1, i) == n) {
            num = i; // Indeks rumah terakhir kemunculan sampah jenis n
            break;
        }
    }

    if (num != -1) {
        for (i = 0; i < num; i++) {
            sum += ELMT(l2, i);
        }
        sum *= 2; // Bolak-balik
    }

    return sum;
}


int main() {
    ListStatik l1, l2;
    readList(&l1); //rumah dan jenis sampah: 1 besi, 2 kertas, 3 glass
    readList(&l2);
    int i, a, sum = 0;

    for (i = 0; i < listLength(l1); i++) {
        if (ELMT(l1, i) != 0) {
            sum += 1; // Ambil sampah 1 menit
        }
    }

    int besi = findfirst(l1, l2, 1);
    int kertas = findfirst(l1, l2, 2);
    int glass = findfirst(l1, l2, 3);

    sum += besi + kertas + glass;


    printf("%d\n", sum);
}