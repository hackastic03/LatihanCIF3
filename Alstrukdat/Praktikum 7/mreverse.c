#include "queue.h"
#include <stdio.h>
#include "boolean.h"
// #include "queue.c"

void reverse(Queue *q) {
    int temp;
    if (length(*q) == 0) {
        return;
    }
    dequeue(q, &temp);
    reverse(q);
    enqueue(q, temp);
}

int main() {
    Queue q, q1;
    CreateQueue(&q);
    CreateQueue(&q1);
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    int i, angka;
    for (i = 0; i < n1; i++) {
        scanf("%d", &angka);
        enqueue(&q, angka);
    }
    // displayQueue(q);

    for (i = 0; i < n2; i++) {
        int temp;
        temp = q.buffer[i];
        enqueue(&q1, temp);
    }
    reverse(&q1);
    for (i = 0; i< n2; i++) {
        q.buffer[i] = q1.buffer[i];
    }
    displayQueue(q);

}