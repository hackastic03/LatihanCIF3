#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"
//#include "liststatik.c"
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
    int a, sum = 0, sum2 = 0, i;
    a = 0;
    for (i = listLength(l1) - 1; i >= 0; i--) {
        sum += pangkatb(ELMT(l1, i), a);
        a++;
    }
    a = 0;
    for (i = listLength(l2) - 1; i >= 0; i--) {
        sum2 += pangkatb(ELMT(l2, i), a);
        a++;
    }

    sum += sum2;

    CreateListStatik(&l3);
    // Hitung banyak digit
    int temp = sum;
    int n;
    while (temp > 0) {
        n = temp % 10;
        temp /= 10;
        insertFirst(&l3, n);
    }


    printList(l3);
    printf("\n");

    return 0;
}