#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list_circular.h"
#include "list_circular.c"

void insertAt(List *l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst(l, val);
    }
    else {
        Address P = allocate(val);
        Address Prec = FIRST(*l);
        int i;
        for (i = 0; i < idx - 1; i++) {
            Prec = NEXT(Prec);
        }
        NEXT(P) = NEXT(Prec);
        NEXT(Prec) = P;
    }
}

void deleteAt(List *l, ElType *val, int idx) {
    if (idx == 0) {
        deleteFirst(l, val);
    }
    else {
        Address Prec = FIRST(*l);
        int i;
        for (i = 0; i < idx - 1; i++) {
            Prec = NEXT(Prec);
        }
        Address P = NEXT(Prec);
        NEXT(Prec) = NEXT(P);
        *val = INFO(P);
        deallocate(P);
    }
}

int length(List l) {
    Address P = FIRST(l);
    if (isEmpty(l)) {
        return 0;
    }
    if (NEXT(P) == FIRST(l)) {
        return 1;
    }
    else {
        int i = 1;

        while ((P) != FIRST(l)) {
            i++;
            P = NEXT(P);
        }
        return i;
    }
}

void swap(Address *P1, Address *P2) {
    Address temp = NEXT(*P1);
    NEXT(*P1) = NEXT(*P2);
    NEXT(*P2) = temp;
}

void swapInfo(List *l, int id1, int id2) {
    Address P1 = FIRST(*l);
    Address P2 = FIRST(*l);
    int i;
    for (i = 0; i < id1; i++) {
        P1 = NEXT(P1);
    }
    for (i = 0; i < id2; i++) {
        P2 = NEXT(P2);
    }
    ElType temp = INFO(P1);
    INFO(P1) = INFO(P2);
    INFO(P2) = temp;
}


void bubbleSort(List *l) {

    int i, j;
    for (i = 0; i < length(*l); i++) {
        int swapped = 0;
        Address head = FIRST(*l);
        for (j = 0; j < length(*l) - i - 1; j++) {
            Address P1 = head;
            Address P2 = NEXT(P1);
            if (INFO(P1) > INFO(P2)) {
                swap(&P1, &P2);
                swapped = 1;
            }
            head = NEXT(head);
        }
    }
}

int main() {
    List l;
    CreateList(&l);
    int n, info;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        printf("Masukkan info: ");
        scanf("%d", &info);
        insertLast(&l, info);
    }
    printf("List: ");
    displayList(l);
    int n1, n2;
    printf("\nMasukkan angka yang akan di-swap: ");
    scanf("%d", &n1);
    scanf("%d", &n2);
    swapInfo(&l, n1, n2);
    printf("Hasil swap: ");
    displayList(l);
    bubbleSort(&l);
    printf("\nHasil bubble sort: ");
    displayList(l);
}