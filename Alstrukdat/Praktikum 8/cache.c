#include "boolean.h"
#include "listlinier.h"
#include <stdio.h>
// #include "listlinier.c"

int main() {
    int n;
    scanf("%d", &n);
    List L;
    CreateList(&L);
    
    int op;
    scanf("%d", &op);
    if (n != 0) {
        int i;
        int hit = 0;
        float pembagi = 0;
        for (i = 0; i < op; i++) {
            int val;
            scanf("%d", &val);
            if (length(L) != n) {
                if (indexOf(L, val) != IDX_UNDEF) {
                    printf("hit ");
                    hit++;
                    int sisa;
                    deleteAt(&L, indexOf(L, val), &sisa);
                    insertFirst(&L, val);
                }
                else {
                    printf("miss ");
                    insertFirst(&L, val);
                }
                displayList(L);
            }
            else {
                // printf("Full\n");
                int x;
                if (indexOf(L, val) == IDX_UNDEF) {
                    printf("miss ");
                    deleteLast(&L, &x);
                    insertFirst(&L, val);
                }
                else {
                    printf("hit ");
                    hit++;
                    int sisa;
                    deleteAt(&L, indexOf(L, val), &sisa);
                    insertFirst(&L, val);
                }
                    
                    displayList(L);
            }
            printf("\n");
            pembagi++;

            
        }
        if (pembagi == 0) {
            printf("hit ratio: 0\n");
        }
        else { 
            printf("hit ratio: %.2f\n", hit / pembagi);
        }
    }
    else {
        printf("hit ratio: 0\n");
    }

}