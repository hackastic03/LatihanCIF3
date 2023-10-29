#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listsirkuler.h"

boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

Address allocate(ElType val) {
    Address new = (Address) malloc(sizeof(ElmtList));
    if (new != NULL) {
        INFO(new) = val;
        NEXT(new) = NULL;
    }
    return new;
}

void deallocate(Address P) {
    free(P);
}

Address search(List l, ElType val) {
    Address P = FIRST(l);
    while (P != NULL) {
        if (INFO(P) == val) {
            return P;
        }
        P = NEXT(P);
    }
    return NULL;
}

boolean addrSearch(List l, Address p) {
    Address P = FIRST(l);
    while (P != NULL) {
        if (P == p) {
            return true;
        }
        P = NEXT(P);
    }
    return false;
}

void insertFirst(List *l, ElType val) {
    Address P = allocate(val);
    if (P != NULL) {
        if (isEmpty(*l)) {
            NEXT(P) = P;
        } else {
            Address last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(P) = FIRST(*l);
            NEXT(last) = P;
        }
        FIRST(*l) = P;
    }
}

void insertLast(List *l, ElType val) {
    Address P = allocate(val);
    if (P != NULL) {
        if (isEmpty(*l)) {
            insertFirst(l, val);
        } else {
            Address last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(P) = FIRST(*l);
            NEXT(last) = P;
        }
    }
}

void deleteFirst(List *l, ElType * val) {
    if (!isEmpty(*l)) {
        Address P = FIRST(*l);
        *val = INFO(P);
        if (NEXT(P) == P) {
            FIRST(*l) = NULL;
        } else {
            Address last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            FIRST(*l) = NEXT(P);
            NEXT(last) = FIRST(*l);
        }
        deallocate(P);
    }
}

void deleteLast(List *l, ElType *val) {
    if (!isEmpty(*l)) {
        Address P = FIRST(*l);
        if (NEXT(P) == P) {
            deleteFirst(l, val);
        } else {
            Address last = FIRST(*l);
            while (NEXT(NEXT(last)) != FIRST(*l)) {
                last = NEXT(last);
            }
            *val = INFO(NEXT(last));
            deallocate(NEXT(last));
            NEXT(last) = FIRST(*l);
        }
    }
}

void displayList(List l) {
    printf("[");
    if (!isEmpty(l)) {
        Address P = FIRST(l);
        while (NEXT(P) != FIRST(l)) {
            printf("%d", INFO(P));
            P = NEXT(P);
            if (NEXT(P) != FIRST(l)) {
                printf(",");
            }
        }
    }
    printf("]");
}