#include "boolean.h"
#include "queuelinked.h"
#include <stdlib.h>
#include <stdio.h>

Address newNode(ElType x) {
    Address P = (Address) malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}

boolean isEmpty(Queue q) {
    return ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL;
}

int length(Queue q) {
    int count = 0;
    Address P = ADDR_HEAD(q);
    while (P != NULL) {
        count++;
        P = NEXT(P);
    }
    return count;
}

void CreateQueue(Queue *q) {
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("[]");
    }
    else {
        int i;
        printf("[");
        Address P = ADDR_HEAD(q);
        for (i = 0; i < length(q); i++) {
            printf("%d", INFO(P));
            if (i < length(q) - 1) {
                printf(",");
            }
            P = NEXT(P);
        }
        printf("]");
    }
}

void enqueue(Queue *q, ElType x) {
    Address p = newNode(x);
    if (p != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}

void dequeue(Queue *q, ElType *x) {
    Address p = ADDR_HEAD(*q);
    *x = HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q)==NIL) {
        ADDR_TAIL(*q) = NIL;
    }
    NEXT(p) = NIL;
    free(p);
}