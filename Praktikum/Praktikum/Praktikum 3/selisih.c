#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"
// #include "listdin.c"

int main() {
    ListDin l1;
    CreateListDin(&l1, 100);
    readList(&l1);
    int max, min;
    if (listLength(l1) == 1) {
        max = 0; 
        min = 0;
    }
    else {
        extremeValues(l1, &max, &min);  
        max = max + 1;
    }
    printf("%d\n", max - min);
    return 0;
}