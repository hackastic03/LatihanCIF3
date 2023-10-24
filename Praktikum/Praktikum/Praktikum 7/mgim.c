#include "boolean.h"
#include <stdio.h>
#include "queue.h"
// #include "queue.c"


int main() {
    Queue q;
    CreateQueue(&q);
    int n, i;
    int c;
    int step = 0;
    scanf("%d", &n);
    int m = 1;
    int a, b;
    for (i = 0; i < n; i++) {
        step = 0;
        scanf("%d", &c);
        boolean bagi = false;
        a = 1; b = 1; int index = 1;
        while (c > 0) {
            bagi = false;
            b = 1;
            while (b < c){
                a = 1;
                while (a < c) {
                    if (a * b == c && (a != c && b != c && a != 1 && b != 1)) {
                        bagi = true;
                        break;
                    }
                    a++;
                }
                if (bagi) {
                    break;
                }
                b++;
            }
            if (bagi) {
                if (a > b) {
                    c = a;
                }
                else {
                    c = b;
                }
                step++;
            }
            else {
                c--;
                step++;
            }
        }
        m *= step;
    }
    printf("%d\n", m);
}