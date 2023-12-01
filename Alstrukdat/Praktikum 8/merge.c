#include "listlinier.h"
#include "merge.h"
#include "boolean.h"
#include <stdio.h>
//#include "listlinier.c"

void splitList(List source, List* front, List* back) {
    int len = length(source);
    if(len % 2 == 1){
        len++;
    }
    int mid = len / 2;

    *front = source;
    *back = NULL;

    if (len > 1) {
        int i;
        Address P = source;
        for (i = 0; i < mid - 1; i++) {
            P = NEXT(P);
        }

        *back = NEXT(P);
        NEXT(P) = NULL;
    }
}

List merge(List a, List b) {
    List L = NULL;
    Address P1 = a, P2 = b;
    while (P1 != NULL && P2 != NULL) {
        if (INFO(P1) <= INFO(P2)) {
            L = concat(L, newNode(INFO(P1)));
            P1 = NEXT(P1);
        } else {
            L = concat(L, newNode(INFO(P2)));
            P2 = NEXT(P2);
        }
    }
    while (P1 != NULL) {
        L = concat(L, newNode(INFO(P1)));
        P1 = NEXT(P1);
    }
    while (P2 != NULL) {
        L = concat(L, newNode(INFO(P2)));
        P2 = NEXT(P2);
    }
    return L;
}

void mergeSort(List* list) {
    displayList(*list);
    printf("\n");
    if (isEmpty(*list) || NEXT(*list) == NULL) {
        return;
    } else {
        List l1, l2;
        splitList(*list, &l1, &l2);
        mergeSort(&l1);
        mergeSort(&l2);
        *list = merge(l1, l2);
    }
}