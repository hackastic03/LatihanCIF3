#include <stdio.h>
#include "boolean.h"
#include "list_circular.h"
// #include "list_circular.c"

int main() {
    List L;
    CreateList(&L);
    int n, k;
    // Un = a + (n - 1)b
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        insertLast(&L, k);
    }
    int a, b;
    boolean valid = true;
    Address P = FIRST(L);
    
    a = INFO(P);
    b = INFO(NEXT(P)) - INFO(P);
    // printf("%d %d\n", a, b);
    P = NEXT(P);
    int w = 0;
    while (NEXT(P) != FIRST(L)) {
        if (INFO(NEXT(P)) - INFO(P) != b) {
            valid = false;
            break;
        }
        w++;
        P = NEXT(P);
    }
    if (!valid) {
        printf("0 0\n");
    }
    else {
        printf("%d %d\n", b, a);
    }
    return 0;
}