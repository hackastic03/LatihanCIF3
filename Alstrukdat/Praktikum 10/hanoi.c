#include <stdio.h>
#include "boolean.h"
#include "stacklinked.h"
// #include "stacklinked.c"

int main() {
    int N;
    scanf("%d", &N);
    Stack S1, S2, S3;
    CreateStack(&S1);
    CreateStack(&S2);
    CreateStack(&S3);
    int i;
    for (i = 5; i >= 1; i--) {
        push(&S1, i);
    }

    for (i = 0; i < N; i++) {
        int Si;
        int D;
        int temp;
        int asal;
        boolean ada = false;
        scanf("%d", &Si);
        scanf("%d", &D);
        if (Si == 1) {
            if (isEmpty(S1)) {
                printf("Menara kosong\n");
            }
            else {
                pop(&S1, &temp);
                ada = true;
                asal = 1;
            }
        }
        else if (Si == 2) {
            if (isEmpty(S2)) {
                printf("Menara kosong\n");
            }
            else {
                pop(&S2, &temp);
                ada = true;
                asal = 2;
            }
        }
        else {
            if (isEmpty(S3)) {
                printf("Menara kosong\n");
            }
            else {
            pop(&S3, &temp);
            asal = 3;
            ada = true;
            }
        }

        if (ada) {
            if (D == 1) {
                if (isEmpty(S1)) {
                    push(&S1, temp);
                }
                else {
                    if (TOP(S1) > temp) {
                        push(&S1, temp);
                    }
                    else {
                    printf("Piringan tidak dapat dipindah\n");
                    if (asal == 1) {
                        push(&S1, temp);
                    }
                    else if (asal == 2) {
                        push(&S2, temp);
                    }
                    else {
                        push(&S3, temp);
                    }
                    }
                }
            }
            else if (D == 2) {
                if (isEmpty(S2)) {
                    push(&S2, temp);
                }
                else {
                    if (TOP(S2) > temp) {
                        push(&S2, temp);
                    }
                    else {
                    printf("Piringan tidak dapat dipindah\n");
                    if (asal == 1) {
                        push(&S1, temp);
                    }
                    else if (asal == 2) {
                        push(&S2, temp);
                    }
                    else {
                        push(&S3, temp);
                    }}
                }
            }
            else {
                if (isEmpty(S3)) {
                    push(&S3, temp);
                }
                else {
                    if (TOP(S3) > temp) {
                        push(&S3, temp);
                    }
                    else {
                    printf("Piringan tidak dapat dipindah\n");
                    if (asal == 1) {
                        push(&S1, temp);
                    }
                    else if (asal == 2) {
                        push(&S2, temp);
                    }
                    else {
                        push(&S3, temp);
                    }}
                }
            }
        }
    }
    printf("Menara 1: ");
    DisplayStack(S1);
    printf("\n");
    printf("Menara 2: ");
    DisplayStack(S2);
    printf("\n");
    printf("Menara 3: ");
    DisplayStack(S3);
    printf("\n");
    return 0;
}