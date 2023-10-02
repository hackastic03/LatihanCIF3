#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"
#include <math.h>

int pangkatb(int a, int b) {
    int i;
    for (i = 1; i <= b; i++) {
        a = a*10;
    }

    return a;
}

int main() {
    ListStatik l1, l2, l3;
    readList(&l1);
    readList(&l2);
    int a, b, sum, sum2, i, j, pangkat;
    a = 0;
    b = 0;
    for (i = IDX_MIN; i < listLength(l1); i++) {
        pangkat = (listLength(l1) - i - 2);
        if (i != listLength(l1) - 1) {
            a = a + (ELMT(l1, i) * pangkatb(10, pangkat));
        }
        else {
            a += ELMT(l1, i);
        }
    }

    for (i = IDX_MIN; i < listLength(l2); i++) {
        pangkat = (listLength(l2) - i - 2);
        if (i != listLength(l2) - 1) {
            b = b + (ELMT(l2, i) * pangkatb(10, pangkat));
        }
        else {
            b += ELMT(l2, i);
        }
    }
    sum = a + b;
    sum2 = sum;

    CreateListStatik(&l3);
    int n = 1;
    if (sum > 9) {
        while (sum > 9) {
            sum = sum / 10;
            n += 1;
        }
    }
    int sisa;

    for (i = IDX_MIN; i < n; i++) {
        sisa = sum2 % 10;
        sum2 = sum2 / 10;
        ELMT(l3, 4 - i -1) = sisa;
    }
    printList(l3);
    printf("\n");

    return 0;
}