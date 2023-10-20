#include <stdio.h>
#include "boolean.h"
#include "stack.h"
// #include "stack.c"

int main() {
    Stack S;
    CreateEmpty(&S);
    int n, hasil = 0, temp;
    scanf("%d", &n);
    if (n == 0) {
        printf("fibonacci(0)\n");
        hasil = 0;
    }
    else if (n == 1) {
        printf("fibonacci(1)\n");
        hasil = 1;
    }
    else {
        Push(&S, n);
    }
    while (!IsEmpty(S)) {
        if (InfoTop(S) == 0) {
            Pop(&S, &temp);
            printf("fibonacci(%d)\n", temp);
        }
        if (InfoTop(S) == 1) {
            Pop(&S, &temp);
            hasil++;
            printf("fibonacci(%d)\n", temp);
        }
        else if (InfoTop(S) == 2) {
            Pop(&S, &temp);
            printf("fibonacci(%d)\n", temp);
            printf("fibonacci(1)\n");
            printf("fibonacci(0)\n");
            hasil++;
        }
        else {
            Pop(&S, &temp);
            printf("fibonacci(%d)\n", temp);
            Push(&S, temp-2);
            Push(&S, temp-1);
        }
    }

    printf("%d\n", hasil);
}