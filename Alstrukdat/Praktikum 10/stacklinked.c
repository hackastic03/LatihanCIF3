#include <stdio.h>
#include "stacklinked.h"
#include "boolean.h"

Address newNode(ElType x) {
    Address P = (Address) malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}

boolean isEmpty(Stack s) {
    return ADDR_TOP(s) == NULL;
}

int length(Stack s) {
    int count = 0;
    Address P = ADDR_TOP(s);
    while (P != NULL) {
        count++;
        P = NEXT(P);
    }
    return count;
}

void CreateStack(Stack *s) {
    ADDR_TOP(*s) = NULL;
}

void DisplayStack(Stack s) {
    if (isEmpty(s)) {
        printf("[]");
    }
    else {
        int i;
        printf("[");
        Address P = ADDR_TOP(s);
        for (i = 0; i < length(s); i++) {
            printf("%d", INFO(P));
            if (i < length(s) - 1) {
                printf(",");
            }
            P = NEXT(P);
        }
        printf("]");
    }
}

void push(Stack *s, ElType x) {
    Address p = newNode(x);
    if (p != NIL) {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x) {
    Address P = ADDR_TOP(*s);
    *x = INFO(P);
    ADDR_TOP(*s) = NEXT(P);
    free(P);
}

