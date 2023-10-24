#include <stdio.h>
#include "../../Pra-Praktikum/Praktikum 2/boolean.h"
#include "../../Pra-Praktikum/Praktikum 2/liststatik.c"

int main() {
    ListStatik l1, l2, l;
    readList(&l1);
    readList(&l2);
    CreateListStatik(&l);
    sortList(&l1, true);
    sortList(&l2, true);
    int i, j;
    for (i = IDX_MIN; i < listLength(l1); i++) {
        for (j = IDX_MIN; j < listLength(l2); j++) {
            if (ELMT(l1, i) == ELMT(l2, j)) {
                insertLast(&l, ELMT(l1, i));
            }
        }
    }
    sortList(&l, true);
    printf("%d\n", listLength(l));
    printList(l);
    printf("\n");
    return 0;
}