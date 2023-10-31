#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list_circular.h"

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
    boolean found = false;
    if (isEmpty(l)) {
        return NULL;
    }
    while (NEXT(P) != FIRST(l) && !found) {
        if (INFO(P) == val) {
            found = true;
        }
        else {
            P = NEXT(P);
        }
    }
    if (INFO(P) == val) {
        found = true;
    }
    if (found) {
        return P;
    }
    return NULL;
}

boolean addrSearch(List l, Address p) {
    Address P = FIRST(l);
    if (isEmpty(l)) {
        return false;
    }
    if (P == p) {
        return true;
    }
    P = NEXT(P);
    while (P != FIRST(l)) {
        if (P == p) {
            return true;
        }
        P = NEXT(P);
    }
    return false;
}

void insertFirst(List *l, ElType val) {
    Address P = allocate(val);
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

void insertLast(List *l, ElType val) {
    Address P = allocate(val);
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

void deleteFirst(List *l, ElType * val) {
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

void deleteLast(List *l, ElType *val) {
    Address P = FIRST(*l);
    Address previous = NULL;
    if (NEXT(P) == P) {
        deleteFirst(l, val);
    } else {
        Address last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)) {
            previous = last;
            last = NEXT(last);
        }
        *val = INFO(last);
        NEXT(previous) = FIRST(*l);
        free(last);
    }

}

void displayList(List l) {
    printf("[");
    if (!isEmpty(l)) {
        Address P = FIRST(l);
        while (NEXT(P) != FIRST(l)) {
            printf("%d,", INFO(P));
            P = NEXT(P);
        }
        printf("%d", INFO(P));
    }
    printf("]");
}