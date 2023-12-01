#include "listrec.h"
//#include "listrec.c"
#include <stdio.h>
#include "boolean.h"
#include "sort.h"

Address findMiddle(List l) {
    int len = length(l);
    if (len == 0) return NULL;

    int middle = len / 2;
    if (len % 2 == 0) middle--;

    int count = 0;
    Address current = l;

    while (count < middle) {
        current = NEXT(current);
        count++;
    }

    return current;
}

List merge(List l1, List l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (INFO(l1) <= INFO(l2)) {
        NEXT(l1) = merge(NEXT(l1), l2);
        return l1;
    } else {
        NEXT(l2) = merge(l1, NEXT(l2));
        return l2;
    }
}


List mergeSort(List l) {
    if (l == NULL || NEXT(l) == NULL) return l;

    Address middle = findMiddle(l);
    List nextMiddle = NEXT(middle);
    NEXT(middle) = NULL;

    List left = mergeSort(l);
    List right = mergeSort(nextMiddle);

    return merge(left, right);
}


List zigZagSort(List l) {
    int array[length(l)];
    List W = NULL;
    int i, n, len = length(l), j;
    Address P = l;
    for (i = 0; i < len; i++) {
        array[i] = INFO(P);
        P = NEXT(P);
    }
    for (i = 0; i < len; i++) {
        int min = array[i], max = array[i];
        int minIdx = i, maxIdx = i;
        if (i % 2 == 0) {
            for (j = i; j < len; j++) {
                if (array[j] < min) {
                    min = array[j];
                    minIdx = j;
                }
            }
            int temp = array[i];
            array[i] = min;
            array[minIdx] = temp;
        }
        else {
            for (j = i; j < len; j++) {
                if (array[j] > max) {
                    max = array[j];
                    maxIdx = j;
                }
            }
            int temp = array[i];
            array[i] = max;
            array[maxIdx] = temp;
        }
    }
    for (i = 0; i < len; i++) {
        W = konsb(W, array[i]);
    }
    return W;
}



//int main() {
//    List L = NULL;
//    for (int i = 1; i < 10; i++) {
//        L = konsb(L, i);
//    }
//    List W = zigZag(L);
//    displayList(W);
//}