#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

Address newNode(ElType x) {
    Address P = (Address) malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}

boolean isEmpty(List l) {
    return l == NULL;
}

boolean isOneElmt(List l) {
    return length(l) == 1;
}

ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(List l, ElType e) {
    Address p = newNode(e);
    if (p != NIL) {
        NEXT(p) = l;
        l = p;
    }
    return l;
}

List konsb(List l, ElType e) {
    Address p = newNode(e);
    if (p != NIL) {
        if (isEmpty(l)) {
            l = p;
        } else {
            Address last = l;
            while (NEXT(last) != NIL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
    return l;
}

List copy(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return copy(l2);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return length(tail(l)) + 1;
    }
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    } else {
        if (head(l) == x) {
            return true;
        } else {
            return isMember(tail(l), x);
        }
    }
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}