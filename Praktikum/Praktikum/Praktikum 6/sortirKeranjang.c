#include <stdio.h>
#include "stack.h"
// #include "stack.c"

void SortirKeranjang (Stack * S1, Stack * S2) {
    int temp, temp2;
    while (!IsEmpty(*S1)) {
        Pop(S1, &temp);
        while (!IsEmpty(*S2) && temp > InfoTop(*S2)) {
            Pop(S2, &temp2);
            Push(S1, temp2);
        }
        Push(S2, temp);
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
//     printf("\nS2: \n");
//     for (int i = 0; i <= S2.TOP; i++) {
//         printf("%d", S2.T[i]);
//     }
// }