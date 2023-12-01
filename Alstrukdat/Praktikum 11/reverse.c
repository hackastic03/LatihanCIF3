#include "boolean.h"
#include "listrec.h"
//#include "listrec.c"
#include <stdio.h>

List inverseList (List l) {
    if (isEmpty(l)) {
        return NULL;
    }
    else if (isOneElmt(l)) {
        return l;
    }
    else {
        return konsb(inverseList(tail(l)), head(l));
    }
}


int main() {
    List l= NULL;
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        l = konsb(l, temp);
    }
    int q;
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        List l1 = NULL, l2 = NULL;
        int index;
        scanf("%d", &index);
        int j;
        for (j = 0; j < index; j++) {
            l1 = konsb(l1, head(l));
            l = tail(l);
        }
        l1 = inverseList(l1);
        for (j = index; j < n; j++) {
            l2 = konsb(l2, head(l));
            l = tail(l);
        }
        l2 = inverseList(l2);
        l = concat(l1, l2);
    }
    displayList(l);
}
