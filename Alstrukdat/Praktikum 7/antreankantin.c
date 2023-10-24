#include <stdio.h>
#include "boolean.h"
#include "queue.h"
// #include "queue.c"

int main() {
    Queue q;
    CreateQueue(&q);
    boolean done = true;
    int code, time;
    int layan = 0;
    int total = 0;
    while (done) {
        scanf("%d", &code);
        if (code == 0) {
            done = false;
        }
        else if (code == 1) {
            scanf("%d", &time);
            if (isFull(q)) {
                printf("Queue penuh\n");
            }
            else {
                enqueue(&q, time);
            }
        }
        else {
            if (isEmpty(q)) {
                printf("Queue kosong\n");
            }
            else {
                dequeue(&q, &time);
                layan++;
                total += time;
            }
        }
    }
    printf("%d\n", layan);
    float rata = total / (float)layan;
    if (layan != 0) {
        printf("%.2f\n", rata);
    }
    else {
        printf("Tidak bisa dihitung\n");
    }

}