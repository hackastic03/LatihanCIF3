#include "listdin.h"
#include "boolean.h"
#include <stdio.h>
//#include "listdin.c"

void deleteFirst(ListDin *l) {
    int i;
    for (i = 0; i < NEFF(*l); i++) {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    NEFF(*l)--;
}


int main() {
    ListDin l1, l2, l3;
    CreateListDin(&l1, 10000);
    CreateListDin(&l2, 10000);
    CreateListDin(&l3, 20000);
    readList(&l1);
    readList(&l2);
    int i = 0;
    int j = 0;
    while (!isEmpty(l1) || !isEmpty(l2)) {
        if (ELMT(l1, 0) > ELMT(l2, 0)) {
            insertLast(&l3, ELMT(l1, 0));
            deleteFirst(&l1);
        }
        else if (ELMT(l1, 0) == ELMT(l2, 0)) {
            insertLast(&l3, ELMT(l1, 0));
            deleteFirst(&l1);
        }
        else {
            insertLast(&l3, ELMT(l2, 0));
            deleteFirst(&l2);
        }
        if (isEmpty(l1) || isEmpty(l2)) {
            break;
        }
//        printList(l3);
    }
    while (!isEmpty(l1)) {
        insertLast(&l3, ELMT(l1, 0));
        deleteFirst(&l1);
    }
    while (!isEmpty(l2)) {
        insertLast(&l3, ELMT(l2, 0));
        deleteFirst(&l2);
    }
    printList(l3);
    printf("\n");
    return 0;
}