#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) {
    Address new = (Address) malloc(sizeof(Node));
    if (new != NULL) {
        INFO(new) = val;
        NEXT(new) = NULL;
    }
    return new;
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx) {
    Address P = FIRST(l);
    int i = 0;
    while (i < idx) {
        P = NEXT(P);
        i++;
    }
    return INFO(P);
}

void setElmt(List *l, int idx, ElType val) {
    Address P = FIRST(*l);
    int i;
    for (i = 0; i < idx; i++) {
        P = NEXT(P);
    }
    INFO(P) = val;
}

int indexOf(List l, ElType val) {
    Address P = FIRST(l);
    int i = 0;
    while (P != NULL) {
        if (INFO(P) == val) {
            return i;
        }
        P = NEXT(P);
        i++;
    }
    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val) {
    Address P = newNode(val);
    NEXT(P) = FIRST(*l);
    FIRST(*l) = P;
}

void insertLast(List *l, ElType val) {
    if (isEmpty(*l)) {
        insertFirst(l, val);
    }
    else {
        Address P = newNode(val);
        Address Last = FIRST(*l);
        while (NEXT(Last) != NULL) {
            Last = NEXT(Last);
        }
        NEXT(Last) = P;
    }
}

void insertAt(List *l, ElType val, int idx) {
    if (idx == 0) {
                insertFirst(l, val);
    }
    else {
        Address P = newNode(val);
        Address Prec = FIRST(*l);
        int i;
        for (i = 0; i < idx - 1; i++) {
            Prec = NEXT(Prec);
        }
        NEXT(P) = NEXT(Prec);
        NEXT(Prec) = P;
    }
}

void deleteFirst(List *l, ElType *val) {
    Address P = FIRST(*l);
    *val = INFO(P);
    FIRST(*l) = NEXT(P);
    free(P);
}

void deleteLast(List *l, ElType *val) {
    if (NEXT(FIRST(*l)) == NULL) {
        deleteFirst(l, val);
    }
    else {
        Address Last = FIRST(*l);
        while (NEXT(NEXT(Last)) != NULL) {
            Last = NEXT(Last);
        }
        *val = INFO(NEXT(Last));
        free(NEXT(Last));
        NEXT(Last) = NULL;
    }
}

void deleteAt(List *l, int idx, ElType *val) {
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
        *val = INFO(P);
        NEXT(Prec) = NEXT(P);
        free(P);
    }
}

void displayList(List l) {
    printf("[");
    if (!isEmpty(l)) {
        Address P = FIRST(l);
        while (P != NULL) {
            printf("%d", INFO(P));
            P = NEXT(P);
            if (P != NULL) {
                printf(",");
            }
        }
    }
    printf("]");
}

int length(List l) {
    int count = 0;
    Address P = FIRST(l);
    while (P != NULL) {
        count++;
        P = NEXT(P);
    }
    return count;
}

List concat(List l1, List l2)  {
    List l3;
    CreateList(&l3);
    Address(P) = FIRST(l1);
    while (P != NULL) {
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }
    P = FIRST(l2);
    while (P != NULL) {
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }
    return l3;
}