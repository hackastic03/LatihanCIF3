#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main() {
    ListStatik l1, l2, l3;
    readList(&l1);
    readList(&l2);
    CreateListStatik(&l3);
    int i;
    int length = listLength(l1) + listLength(l2);
    for (i = IDX_MIN; i < listLength(l1); i++) {
        ELMT(l3, i) = ELMT(l1, i);
    }
    for (i = IDX_MIN; i < listLength(l2); i++) {
        ELMT(l3, i + listLength(l1)) = ELMT(l2, i);
    }
    sortList(&l3, true);
    printList(l3);
    printf("\n");
    return 0;
}