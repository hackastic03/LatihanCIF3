#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main() {
    ListStatik l1;
    readList(&l1);
    int max, min, n, i, median;
    float rata;
    max = ELMT(l1, IDX_MIN);
    min = ELMT(l1, IDX_MIN);
    scanf("%d", &n);
    sortList(&l1, true);
    printList(l1);
    printf("\n");
    rata = 0;
    for (i = IDX_MIN; i < listLength(l1); i++) {
        rata += ELMT(l1, i);
        if (ELMT(l1, i) > max) {
            max = ELMT(l1, i);
        }
        if (ELMT(l1, i) < min) {
            min = ELMT(l1, i);
        }
    }
    if (listLength(l1) % 2 == 1) {
        median = ELMT(l1, listLength(l1) / 2);
    }
    else {
        median = ELMT(l1, (listLength(l1) / 2) - 1);
    }
    rata = rata / listLength(l1);
    printf("Average: %.02f\n", rata);
    if (indexOf(l1, n) != IDX_UNDEF) {
        printf("%d\n", indexOf(l1, n));
        if (n == max) {
            printf("X maksimum\n");
        }
        if (n == min) {
            printf("X minimum\n");
        }
        if (n == median) {
            printf("X median\n");
        }
    }
    else {
        printf("%d tidak ada\n", n);
    }
    return 0;
}