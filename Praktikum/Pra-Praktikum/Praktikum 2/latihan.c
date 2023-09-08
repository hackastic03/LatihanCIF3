#include "boolean.h"
#include "liststatik.c"
#include <stdio.h>

boolean isSimetris(ListStatik l) {
    if (!isEmpty(l)) {
        int i;
        for (i = IDX_MIN; i < listLength(l); i++) {
            if (ELMT(l, i) != ELMT(l, (listLength(l) - 1 - i))) {
                return false;
            }
        }
        return true;
    }
    return true;
}

void insertUnique(ListStatik *l) {
    int x;
    scanf("%d", &x);
    if (isEmpty(*l)) {
        insertLast(l, x);
    }
    else {
        while (indexOf(*l, x) != IDX_UNDEF) {
            printf("Nilai sudah ada\n");
            scanf("%d", &x);
        }
        insertLast(l, x);
    }
}

int main() {
    ListStatik l1;
    readList(&l1);
    printList(l1);
    printf("\nList sama: %d\n", isSimetris(l1));
    insertUnique(&l1);
    printList(l1);
    return 0;
}