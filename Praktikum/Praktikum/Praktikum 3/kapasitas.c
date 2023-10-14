#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"
//#include "listdin.c"
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    ListDin l1;
    CreateListDin(&l1, 0);
    int i;
    for (i = 0; i < n; i++) {
        int tipe;
        scanf("%d",&tipe);
        if(tipe==1){
            int x;
            scanf("%d",&x);
            if (CAPACITY(l1) == 0) {
                expandList(&l1, 1);
            }
            else {
                if (isFull(l1)) {
                    expandList(&l1, CAPACITY(l1));
                }
            }
            insertLast(&l1, x);
        // proses query tipe 1
        }
        else if(tipe==2){
            int val;
            deleteLast(&l1, &val);
            if (NEFF(l1) <= round(CAPACITY(l1) / 2) ) {
//                shrinkList(&l1, round(CAPACITY(l1) / 2));
                CAPACITY(l1) = round(CAPACITY(l1) / 2);
                BUFFER(l1) = realloc(BUFFER(l1), CAPACITY(l1) * sizeof(ElType));
            }
        // proses query tipe 2
        }
        else{
            printf("%d ", CAPACITY(l1));
            printList(l1);
            printf("\n");
        // proses query tipe 3
        }
    }
    return 0;
}