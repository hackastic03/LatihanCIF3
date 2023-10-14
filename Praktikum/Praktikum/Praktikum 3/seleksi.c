#include "listdin.h"
#include "boolean.h"
#include <stdio.h>
//#include "listdin.c"


void delete(ListDin *l, int index) {
    int i;
    for (i = index; i < NEFF(*l); i++) {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    NEFF(*l)--;
}


int main() {
    ListDin l;
    int a;
    scanf("%d", &a);
    CreateListDin(&l, a);
    int b, i;
    scanf("%d", &b);
    for (i = 0; i < b; i++) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            int x;
            scanf("%d", &x);
            int j = 0;
            while (j < NEFF(l)) {
                if (ELMT(l, j) < x) {
                    delete(&l, j);
                    j--;
                }
                j++;
            }
            insertLast(&l, x);
        }
        else {
            printf("%d\n", listLength(l));
            printList(l);
            printf("\n");
        }
    }
}