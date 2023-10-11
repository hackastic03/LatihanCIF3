#include <stdio.h>
#include "boolean.h"
#include "stack.h"
// #include "stack.c"

int call(int n) {
    if (n == 0) {
        printf("fibonacci(0)\n");
        return 0;
    }
    else if (n == 1) {
        printf("fibonacci(1)\n");
        return 1;
    }
    else {
        printf("fibonacci(%d)\n", n);
        return call(n - 1) + call(n - 2);
    }
}



int main() {
    int n, sum;
    scanf("%d", &n);
    // Stack S;
    // CreateEmpty(&S);
    // int sum, temp;
    // int i, x, j;
    // for (i = 1; i <= n; i++) {
    //     Push(&S, i);
    // }
    // for (i = 0; i < Top(S); i++) {
    //     Pop(&S, &x);
    //     for (j = x; j >= 0; j--) {
    //         printf("fibonacci(%d)\n", j);
    //     }
    // }
    sum = call(n);
    printf("%d\n", sum);
}