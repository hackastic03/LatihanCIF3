#include "listlinier.h"
#include "merge.h"
#include "boolean.h"
#include <stdio.h>
#include "listlinier.c"

void splitList(List source, List* front, List* back) {
    int len = length(source);
    Address p1 = FIRST(source);
    int i, a, b =0;
    if (len % 2 == 0) {
        a = len / 2;
    }
    else {
        a = (len / 2) + 1;
    }
    while (b != a) {
            insertLast(front, INFO(p1));
            p1 = NEXT(p1);
            b++;
        }
        while (p1 != NULL) {
            insertLast(back, INFO(p1));
            p1 = NEXT(p1);
        }
}

List merge(List a, List b) {
    List l;
    CreateList(&l);
    if (FIRST(a) == NULL) {
        return b;
    }
    else if (FIRST(b) == NULL) {
        return a;
    }
    else {
        l = concat(a, b);
        Address P1 = FIRST(l);
        Address P2 = FIRST(l);
        int i, j, len = length(l);
        for (i = 0; i < len; i++) {
            for (j = 0; j < len; j++) {
                if (INFO(P1) > INFO(P2)) {
                    Address temp = P1;
                    P1 = P2;
                    P2 = temp;
                }
                P1 = NEXT(P1);
            }
            P2 = NEXT(P2);

        }


        return l;
    }
}

void mergeSort(List* list) {
    Address head = FIRST(*list);
    if (head == NULL || NEXT(head) == NULL) {
        return;
    }
    List front, back;
    CreateList(&front);
    CreateList(&back);
    splitList(*list, &front, &back);
    mergeSort(&front);
    mergeSort(&back);
    merge(front, back);
}