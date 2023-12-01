#include <stdio.h>
#include "boolean.h"
#include "deque.h"

Address newNode(ElType x) {
    Address P = (Address) malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
boolean isEmpty(Deque q) {
    return (ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */
int length(Deque q) {
    if (isEmpty(q)) {
        return 0;
    }
    else {
        Address P = ADDR_HEAD(q);
        int i = 0;
        while (P != NULL) {
            i++;
            P = NEXT(P);
        }
        return i;
    }
}
/* Mengirimkan banyaknya elemen Deque. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateDeque(Deque *q) {
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
void DisplayDeque(Deque q) {
    if (isEmpty(q)) {
        printf("[]");
    }
    else {
        int i;
        printf("[");
        Address P = ADDR_HEAD(q);
        for (i = 0; i < length(q); i++) {
            printf("%d", INFO(P));
            if (i < length(q) - 1) {
                printf(",");
            }
            P = NEXT(P);
        }
        printf("]");
    }
}
/* Proses : Menuliskan isi Deque, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Deque kosong : menulis [] */

/*** Primitif Enqueue/Dequeue ***/
void EnqueueHead(Deque *q, ElType x) {
    Address p = newNode(x);
    if (p != NIL) {
        if (isEmpty(*q)) {
            ADDR_TAIL(*q) = p;
        }
        else {
            NEXT(p) = ADDR_HEAD(*q);
        }
    }
    ADDR_HEAD(*q) = p;
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian HEAD dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertFirst */
/* I.S. q mungkin kosong */
/* F.S. x menjadi HEAD, HEAD "maju" */
void DequeueHead(Deque *q, ElType *x) {
    Address p = ADDR_HEAD(*q);
    *x = HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q)==NIL) {
        ADDR_TAIL(*q) = NIL;
    }
    NEXT(p) = NIL;
    free(p);
}
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
void EnqueueTail(Deque *q, ElType x) {
    Address p = newNode(x);
    if (p != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian TAIL dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi TAIL, TAIL "mundur" */
void DequeueTail(Deque *q, ElType *x) {
    if (length(*q) == 1) {
        DequeueHead(q, x);
    }
    else {
        Address p = ADDR_HEAD(*q);
        *x = TAIL(*q);
        Address temp = ADDR_TAIL(*q);
        while (NEXT(NEXT(p)) != NULL) {
            p = NEXT(p);
        }
        NEXT(p) = NULL;
        ADDR_TAIL(*q) = p;
        free(temp);
    }
}