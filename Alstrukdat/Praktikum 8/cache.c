#include "boolean.h"
#include "listlinier.h"
#include <stdio.h>
// #include "listlinier.c"

int main() {
    int n;
    scanf("%d", &n);
    int i, op, temp;
    List L;
    CreateList(&L);
    scanf("%d", &op);
    float hit = 0;
    if (op > 0) {
        for (i = 0; i < op; i++) {
            int val;
            scanf("%d", &val);
            if (isEmpty(L)) {
                if (length(L) < n) {
                    insertFirst(&L, val);
                }
                printf("miss ");
                displayList(L);
                printf("\n");
            }
            else if (indexOf(L, val) != IDX_UNDEF) {
                hit++;
                deleteAt(&L, indexOf(L, val), &temp);
                insertFirst(&L, val);
                printf("hit ");
                displayList(L);
                printf("\n");
            }
            else if (length(L) == n) {
                deleteLast(&L, &temp);
                insertFirst(&L, val);
                printf("miss ");
                displayList(L);
                printf("\n");
            }
            else {
                insertFirst(&L, val);
                printf("miss ");
                displayList(L);
                printf("\n");
            }
        }
        double ratio = hit / op;
        printf("hit ratio: %.2f\n", ratio);
    }
    else {
        printf("hit ratio: 0.00\n");
    }
    return 0;

}