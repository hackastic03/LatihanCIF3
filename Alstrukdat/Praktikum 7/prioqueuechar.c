#include <stdio.h>
#include "boolean.h"
#include "prioqueuechar.h"
#include <stdlib.h>

/*
#define Prio(e)     (e).prio
#define Info(e)     (e).info
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxEl
#define Elmt(Q,i)   (Q).T[(i)]
*/

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q) {
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}

/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueChar Q) {
    return (Q.HEAD == 0) && (Q.TAIL == Q.MaxEl - 1);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueChar Q) {
    if (IsEmpty(Q)) {
        return 0;
    }
    else if (Head(Q) <= Tail(Q)) {
        return Tail(Q) - Head(Q) + 1;
    }
    else {
        return (MaxEl(Q) - Head(Q)) + (Tail(Q) + 1);
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max) {
    (*Q).HEAD = Nil;
    (*Q).TAIL = Nil;
    (*Q).T = (infotype*) malloc(Max + 1);
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q) {
    MaxEl(*Q) = 0;
    (*Q).HEAD = Nil;
    (*Q).TAIL = Nil;
    free(Q);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X) {
    if (IsEmpty(*Q)) {
        (*Q).HEAD = 0;
        (*Q).TAIL = 0;
        Prio((*Q).T[0]) = X.prio;
        Info((*Q).T[0]) = X.info;
    }
    else {
        int i, index = 0;
        if (Tail(*Q) == MaxEl(*Q) - 1) {
            Tail(*Q) = 0;
        }
        else {
            Tail(*Q)++;
        }
        for (i = 1; i < NBElmt(*Q); i++) {
            // Cari indeks dulu
            if (X.prio > Prio(Elmt(*Q, i) )) {
                index = i - 1;
                break;
            }
        }
        for (i = NBElmt(*Q) - 1; i > index; i--) {
            (*Q).T[i] = (*Q).T[i - 1];
        }
        (*Q).T[index] = X;    
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueChar * Q, infotype * X) {
    *X = Q->T[Head(*Q)];
    if (NBElmt(*Q) == 1) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else {
        if (Head(*Q) == MaxEl(*Q) - 1) {
            Head(*Q) = 0;
        }
        else {
            Head(*Q)++;
        }
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q) {
    int i;
    for (i = 0; i < NBElmt(Q); i++) {
        printf("%d %c\n", Prio(Q.T[i]), Info(Q.T[i]));
    }
    printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

int main() {
    PrioQueueChar p;
    int nmax;
    printf("Masukkan MaxEl:");
    scanf("%d", &nmax);
    MakeEmpty(&p, nmax);
    infotype x;
    int prio, n;
    char c;
    printf("Masukkan jumlah elemen:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &prio, &c);
        Prio(x) = prio;
        Info(x) = c;
        Enqueue(&p, x);
        printf("Length: %d\n", NBElmt(p));
        PrintPrioQueueChar(p);
    }
    PrintPrioQueueChar(p);
    return 0;
}