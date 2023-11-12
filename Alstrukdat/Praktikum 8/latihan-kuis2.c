#include <stdio.h>
#include "listlinier.h"
#include "listlinier.c"

Address minNode(Address P1, Address P2) {
    if (INFO(P1) < INFO(P2)) {
        return P1;
    } else {
        return P2;
    }
}


int searchX(List L, Address X) {
    Address P = FIRST(L);
    int i = 0;
    while (P != NULL) {
        if (P == X) {
            return i;
        }
        P = NEXT(P);
        i++;
    }
    return IDX_UNDEF;
}

boolean isInVal(List L, int val) {
    Address P = FIRST(L);
    while (P != NULL) {
        if (INFO(P) == val) {
            return true;
        }
        P = NEXT(P);
    }
    return false;
}

boolean isInAddress(List L, Address P) {
    Address P1 = FIRST(L);
    while (P1 != NULL) {
        if (P1 == P) {
            return true;
        }
        P1 = NEXT(P1);
    }
    return false;
}


List sortedIntersect(List *l1, List *l2) {
    List L3;
    CreateList(&L3);
    Address P1 = FIRST(*l1);
    while (P1 != NULL) {
        Address P2 = FIRST(*l2);
        while (P2 != NULL) {
            if (INFO(P1) == INFO(P2)) {
                if (!isInVal(L3, INFO(P1))) {
                    if (isEmpty(L3)) {
                        insertFirst(&L3, INFO(P1));
                    }
                    else {
                        Address P3 = FIRST(L3);
                        int idx = 0;
                        while (P3 != NULL || INFO(P1) < INFO(P3)) {
                            idx++;
                            P3 = NEXT(P3);
                        }
                        insertAt(&L3, INFO(P1), idx);
                    }
                }
            }
            P2 = NEXT(P2);
        }
        P1 = NEXT(P1);
    }
    return L3;
}

void sortedMerge(List *L1, List L2) {
    Address P1 = FIRST(*L1);
    Address P2 = FIRST(L2);
}

int main() {
    List L;
    CreateList(&L);
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        ElType val;
        scanf("%d", &val);
        insertLast(&L, val);
    }
    displayList(L);
    printf("\n");
    printf("Index untuk elemen pertama adalah %d\n", searchX(L, FIRST(L)));

}