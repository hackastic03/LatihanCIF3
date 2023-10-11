#include <stdio.h>
#include "stack.h"
// #include "stack.c"


// int minim(int a, int b) {
//     if (a < b) {
//         return a;
//     }
//     else {
//         return b;
//     }
// }


void SortirKeranjang (Stack * S1, Stack * S2) {
    int min;
    int i, temp, j;
    for (i = 0; i <= S1->TOP; i++) {
        for (j = i; j <= S1->TOP; j++) {
            if (S1->T[j] > S1->T[i]) {
                temp = S1->T[i];
                S1->T[i] = S1->T[j];
                S1->T[j] = temp;
            }
        }
    }
    // for (i = 0; i <= S1->TOP; i++) {
    //     printf("%d\n", S1->T[i]);
    // }
    int x;
    for (i = S1->TOP; i >= 0; i--) {
        Push(S2, S1->T[i]);
        Pop(S1, &x);
    }
} 

// int main() {
//     Stack S1, S2;
//     CreateEmpty(&S1);
//     CreateEmpty(&S2);
//     int x, n;
//     scanf("%d", &n);
//     printf("S1: \n");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &x);
//         Push(&S1, x);
//     }
//     SortirKeranjang(&S1, &S2);
//     printf("S1: \n");
//     for (int i = 0; i <= S1.TOP; i++) {
//         printf("%d", S1.T[i]);
//     }
//     printf("\nS2: \n");
//     for (int i = 0; i <= S2.TOP; i++) {
//         printf("%d", S2.T[i]);
//     }
// }