#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listganda.h"

Address newNode(ElType val) {
    Address new = (Address) malloc(sizeof(Node));
    if (new != NULL) {
        INFO(new) = val;
        NEXT(new) = NULL;
        PREV(new) = NULL;
    }
    return new;
}

void createListGanda(ListGanda *l) {
    CURRENT(*l) = NULL;
}

boolean isEmpty(ListGanda l) {
    return CURRENT(l) == NULL;
}

boolean isOneElement(ListGanda l) {
    return !isEmpty(l) && NEXT(CURRENT(l)) == CURRENT(l) && PREV(CURRENT(l)) == CURRENT(l);
}

int length(ListGanda l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        int count = 1;
        Address current = CURRENT(l);
        Address next = NEXT(current);
        while (next != CURRENT(l)) {
            count++;
            current = next;
            next = NEXT(current);
        }
        return count;
    }
}

void rotate(ListGanda *l, int k) {
    if (!isEmpty(*l)) {
        if (k >= 0) {
            for (int i = 0; i < k; i++) {
                CURRENT(*l) = NEXT(CURRENT(*l));
            }
        } else {
            for (int i = 0; i < -k; i++) {
                CURRENT(*l) = PREV(CURRENT(*l));
            }
        }
    }
}

void insertAfterCurrent(ListGanda *l, ElType x) {
    Address P = newNode(x);
    if (P != NULL) {
        if (isEmpty(*l)) {
            CURRENT(*l) = P;
            NEXT(P) = P;
            PREV(P) = P;
        } else {
            Address next = NEXT(CURRENT(*l));
            NEXT(P) = next;
            PREV(P) = CURRENT(*l);
            NEXT(CURRENT(*l)) = P;
            CURRENT(*l) = P;
            PREV(next) = P;
        }
    }
}

void deleteCurrent(ListGanda *l, ElType *x) {
    if (!isEmpty(*l)) {
        *x = INFO(CURRENT(*l));
        if (isOneElement(*l)) {
            free(CURRENT(*l));
            createListGanda(l);
        } else {
            Address prev = PREV(CURRENT(*l));
            Address next = NEXT(CURRENT(*l));
            NEXT(prev) = next;
            PREV(next) = prev;
            free(CURRENT(*l));
            CURRENT(*l) = next;
        }
    }
}