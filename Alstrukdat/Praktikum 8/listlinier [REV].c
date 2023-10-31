#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) {
    Address new = (Address) malloc(sizeof(Node));
    if (new != NULL) {
        INFO(new) = val;
        NEXT(new) = NULL;
    }
    return new;
}


void CreateList(List *l) {
    FIRST(*l) = NULL;
}

boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx) {
    Address P = FIRST(l);
    int i = 0;
    while (i < idx) {
        P = NEXT(P);
        i++;
    }
    return INFO(P);
}

void setElmt(List *l, int idx, ElType val) {
    Address P = FIRST(*l);
    int i;
    for (i = 0; i < idx; i++) {
        P = NEXT(P);
    }
    INFO(P) = val;
}

int indexOf(List l, ElType val) {
    Address P = FIRST(l);
    int i = 0;
    while (P != NULL) {
        if (INFO(P) == val) {
            return i;
        }
        P = NEXT(P);
        i++;
    }
    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val) {
    Address P = newNode(val);
    NEXT(P) = FIRST(*l);
    FIRST(*l) = P;
}

void insertLast(List *l, ElType val) {
    if (isEmpty(*l)) {
        insertFirst(l, val);
    }
    else {
        Address P = newNode(val);
        Address Last = FIRST(*l);
        while (NEXT(Last) != NULL) {
            Last = NEXT(Last);
        }
        NEXT(Last) = P;
    }
}

void insertAt(List *l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst(l, val);
    }
    else {
        Address P = newNode(val);
        Address Prec = FIRST(*l);
        int i;
        for (i = 0; i < idx - 1; i++) {
            Prec = NEXT(Prec);
        }
        NEXT(P) = NEXT(Prec);
        NEXT(Prec) = P;
    }
}

void deleteFirst(List *l, ElType *val) {
    Address P = FIRST(*l);
    *val = INFO(P);
    FIRST(*l) = NEXT(P);
    free(P);
}

void deleteLast(List *l, ElType *val) {
    if (NEXT(FIRST(*l)) == NULL) {
        deleteFirst(l, val);
    }
    else {
        Address Last = FIRST(*l);
        while (NEXT(NEXT(Last)) != NULL) {
            Last = NEXT(Last);
        }
        *val = INFO(NEXT(Last));
        free(NEXT(Last));
        NEXT(Last) = NULL;
    }
}

void deleteAt(List *l, int idx, ElType *val) {
    if (idx == 0) {
        deleteFirst(l, val);
    }
    else {
        Address Prec = FIRST(*l);
        int i;
        for (i = 0; i < idx - 1; i++) {
            Prec = NEXT(Prec);
        }
        Address P = NEXT(Prec);
        *val = INFO(P);
        NEXT(Prec) = NEXT(P);
        free(P);
    }
}

void displayList(List l) {
    printf("[");
    if (!isEmpty(l)) {
        Address P = FIRST(l);
        while (P != NULL) {
            printf("%d", INFO(P));
            P = NEXT(P);
            if (P != NULL) {
                printf(",");
            }
        }
    }
    printf("]");
}

int length(List l) {
    int count = 0;
    Address P = FIRST(l);
    while (P != NULL) {
        count++;
        P = NEXT(P);
    }
    return count;
}

List concat(List l1, List l2)  {
    List l3;
    CreateList(&l3);
    Address(P) = FIRST(l1);
    while (P != NULL) {
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }
    P = FIRST(l2);
    while (P != NULL) {
        insertLast(&l3, INFO(P));
        P = NEXT(P);
    }
    return l3;
}

// NILAI EKSTREM


ElType maxValue(List l) {
    ElType max = INFO(FIRST(l));
    Address P = FIRST(l);
    while (P != NULL) {
        if (INFO(P) > max) {
            max = INFO(P);
        }
        P = NEXT(P);
    }
    return max;

}
/* Mengirimkan nilai info(P) yang maksimum */
Address adrMax(List l) {
    ElType max = INFO(FIRST(l));
    Address P = FIRST(l);
    while (NEXT(P) != NULL) {
        if (INFO(P) > max) {
            max = INFO(P);
        }
        if (NEXT(P) == NULL) {
            break;
        }
        P = NEXT(P);
        
    }
    return P;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
ElType minValue(List l) {
    ElType min = INFO(FIRST(l));
    Address P = FIRST(l);
    while (P != NULL) {
        if (INFO(P) < min) {
            min = INFO(P);
        }
        P = NEXT(P);
    }
    return min;
}
/* Mengirimkan nilai info(P) yang minimum */
Address adrMin(List l) {
    ElType min = INFO(FIRST(l));
    Address P = FIRST(l);
    while (P != NULL) {
        if (INFO(P) < min) {
            min = INFO(P);
        }
        if (NEXT(P) == NULL) {
            break;
        }
        P = NEXT(P);
    }
    return P;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float average(List L) {
    ElType total = 0;
    Address P = FIRST(L);
    while (P != NULL) {
        total += INFO(P);
        P = NEXT(P);
    }
    return total / (float) length(L);
}
/* Mengirimkan nilai rata-rata info(P) */



void deleteAll(List *l) {
    Address P = FIRST(*l);
    int val;
    while (P != NULL) {
        deleteFirst(l, &val);
        FIRST(*l) = NEXT(P);
        P = NEXT(P);
    }
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void copyList(List *l1, List *l2) {
    List l;
    CreateList(&l);
    *l2 = concat(*l1, l);
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

void inverseList(List *l) {
    Address P = FIRST(*l);
    ElType val;
    if (length(l) == 0) {
        return;
    }
    deleteLast(l, &val);
    inverseList(l);
    insertFirst(l, val);
}


boolean fSearch(List L, Address P) {
    Address x = FIRST(L);
    while (P != NULL) {
        if (P == x) {
            return true;
        }
        x = NEXT(x);
    }
    return false;
}
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
Address searchPrec(List L, ElType X) {

}