#include <stdio.h>
#include "queue.h"
#include "boolean.h"

void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q) {
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFull(Queue q) {
    return (IDX_HEAD(q) == 0) && (IDX_TAIL(q) == CAPACITY - 1);
}

int length(Queue q) {
    if (isEmpty(q)) {
        return 0;
    }
    else if (IDX_HEAD(q) <= IDX_TAIL(q)) {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
    else {
        return (CAPACITY - IDX_HEAD(q)) + (IDX_TAIL(q) + 1);
    }
}

void enqueue(Queue *q, ElType val) {
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else {
        if (IDX_TAIL(*q) == CAPACITY - 1) {
            IDX_TAIL(*q) = 0;
        }
        else {
            IDX_TAIL(*q)++;
        }
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val) {
    *val = HEAD(*q);
    if (length(*q) == 1) {
        IDX_TAIL(*q) = IDX_UNDEF;
        IDX_HEAD(*q) = IDX_UNDEF;
    }
    else {
        if (IDX_HEAD(*q) == CAPACITY - 1) {
            IDX_HEAD(*q) = 0;
        }
        else {
            IDX_HEAD(*q)++;
        }
    }
}

void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("[]");
    }
    else {
        printf("[");
        int i = IDX_HEAD(q);
        while (i != IDX_TAIL(q)) {
            printf("%d,", q.buffer[i]);
            if (i == CAPACITY - 1) {
                i = 0;
            }
            else {
                i++;
            }
        }
        printf("%d]", q.buffer[i]);
    }
    printf("\n");
}