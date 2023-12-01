#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

Address newNode(ElType x) {
    Address P = (Address) malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}

boolean isEmpty(List l) {
    return l == NULL;
}

boolean isOneElmt(List l) {
    return length(l) == 1;
}

ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(List l, ElType e) {
    Address p = newNode(e);
    if (p != NIL) {
        NEXT(p) = l;
        l = p;
    }
    return l;
}

List konsb(List l, ElType e) {
    Address p = newNode(e);
    if (p != NIL) {
        if (isEmpty(l)) {
            l = p;
        } else {
            Address last = l;
            while (NEXT(last) != NIL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
    return l;
}

List copy(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return copy(l2);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return length(tail(l)) + 1;
    }
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    } else {
        if (head(l) == x) {
            return true;
        } else {
            return isMember(tail(l), x);
        }
    }
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}


List insertAt(List l, ElType e, int idx) {

    if (idx == 0) {

        Address new_node = (Address) malloc(sizeof(Node));

        new_node->info = e;

        new_node->next = l;

        return new_node;

    } else {

        l->next = insertAt(l->next, e, idx - 1);

        return l;

    }

}
/* Fungsi untuk menambahkan e sebagai elemen pada posisi/index idx sebuah list l */

List deleteFirst(List l) {
    return tail(l);
}
/* Fungsi untuk menghapus elemen pertama sebuah list l */

List deleteAt(List l, int idx) {
    if (l == NULL) return l;
    if (idx == 0) {
        Address temp = l;
        l = NEXT(l);
        free(temp);
        return l;
    }
    NEXT(l) = deleteAt(NEXT(l), idx - 1);
    return l;
}
/* Fungsi untuk menghapus elemen pada posisi/index idx sebuah list l */

List deleteLast(List l) {
    if (NEXT(l) == NULL) {
        l = deleteFirst(l);
    }
    else {
        Address Last = l;
        while (NEXT(NEXT(Last)) != NULL) {
            Last = NEXT(Last);
        }
        NEXT(Last) = NULL;
    }
    return l;
}
/* Fungsi untuk menghapus elemen terakhir sebuah list l */


/*** Operasi-Operasi Lain ***/
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
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void splitPosNeg (List l, List *l1, List *l2) {
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    }
    else {
        if (head(l) >= 0){
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1,head(l));
        }
        else{
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2,head(l));
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */

void splitOnX (List l, ElType x, List *l1, List *l2) {
    int i = 0;
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    }
    else {
        splitOnX(tail(l),x,l1,l2);
        if (head(l) < x){
            *l1 = konso(*l1,head(l));
        }
        else{
            *l2 = konso(*l2, head(l));
        }
    }
}
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */

List isExist(List l, ElType e) {
    if (l == NULL) return NULL;

    if (INFO(l) == e) return l;

    return isExist(NEXT(l), e);
}

List removeDuplicate(List L, List unique) {
    if (L == NULL) return unique;

    Address existing = isExist(unique, INFO(L));

    if (existing == NULL) {
        Address newNode = (Address)malloc(sizeof(Node));
        INFO(newNode) = INFO(L);
        NEXT(newNode) = unique;
        unique = newNode;
    }

    return removeDuplicate(NEXT(L), unique);
}


// int main() {
//     List l;
//     int n;
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++) {
//         int temp;
//         scanf("%d", &temp);
//         l = konsb(l, temp);
//     }
//     l = inverseList(l);
//     List uniq = NULL;
//     uniq = removeDuplicate(l, uniq);
//     displayList(l);
// }