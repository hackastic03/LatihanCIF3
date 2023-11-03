#include "listlinier.h"
#include "merge.h"
#include "boolean.h"
#include <stdio.h>
//#include "listlinier.c"

void splitList(List source, List* front, List* back) {
    int len = length(source);
    Address p1 = FIRST(source);
    int i, a, b = 0;
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
    while (p1 != FIRST(source)) {
        insertLast(back, INFO(p1));
        p1 = NEXT(p1);
    }

}

List merge(List a, List b) {
    if (isEmpty(a)) {
        return b;
    }
    if (isEmpty(b)) {
        return a;
    }
    Address temp;
    if (INFO(a) > INFO(b)) {
        temp = a;
        NEXT(temp) = merge(NEXT(a), b);
    }
    else {
        temp = b;
        NEXT(temp) = merge(a, NEXT(b));
    }
    return temp;
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