/* Reverse sebuah queue */

#include "queue.h"
#include "boolean.h"
#include <stdio.h>
#include "queue.c"

void reverse(Queue *q) {
    if (length(*q) == 0) {
        return;
    }
    else {
        int temp = HEAD(*q);
        dequeue(q, &temp);
        reverse(q);
        enqueue(q, temp);
    }
}

int main() {
    Queue q;
    CreateQueue(&q);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ElType temp;
        scanf("%d", &temp);
        enqueue(&q, temp);
    }
    reverse(&q);
    while (!isEmpty(q)) {
        ElType temp;
        dequeue(&q, &temp);
        printf("%d\n", temp);
    }
    return 0;
}