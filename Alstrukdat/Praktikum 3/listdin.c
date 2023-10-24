#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity) {
    BUFFER(*l) = (ElType*) malloc(capacity * sizeof(int));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l) {
    NEFF(*l) = 0;
    free(BUFFER(*l));
    CAPACITY(*l) = 0;

}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l) {
    return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l) {
    return IDX_MIN;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDin l) {
    return NEFF(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i) {
    return (i < CAPACITY(l)) && (i >= IDX_MIN);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i) {
    return (i <= NEFF(l)) && (i >= IDX_MIN);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l) {
    return (NEFF(l) == 0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l) {
    return (NEFF(l) == CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l) {
    int n, i = IDX_MIN;
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY(*l)) {
        scanf("%d", &n);
    }
    NEFF(*l) = n;
    for(i = IDX_MIN; i < n; i++) {
        scanf("%d", &ELMT(*l, i));
    }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList(ListDin l) {
    printf("[");
    if (!isEmpty(l)) {
        int i;
        for (i = IDX_MIN; i < listLength(l); i++) {
            printf("%d", ELMT(l, i));
            if (i < listLength(l) - 1) {
                printf(",");
            }
        }
    }
    printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    ListDin l3;
    CreateListDin(&l3, NEFF(l1));
    int i;
    NEFF(l3) = listLength(l1);
    for (i = IDX_MIN; i < NEFF(l3); i++) {
        if (plus) {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
        else {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l3;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2) {
    if (listLength(l1) == listLength(l2)) {
        int i;
        for (i = IDX_MIN; i < listLength(l1); i++) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                return false;
            }
        }
        return true;
    }
    return false;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val) {
    int i;
    if (isEmpty(l)) {
        return IDX_UNDEF;
    }
    else {
        for (i = IDX_MIN; i < listLength(l); i++) {
            if (ELMT(l, i) == val) {
                return i;
            }
        }
        return IDX_UNDEF;
    }
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min) {
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);
    int i;
    for (i = IDX_MIN; i < listLength(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut) {
    CreateListDin(lOut, listLength(lIn));
    int i;
    for (i = IDX_MIN; i < listLength(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    CAPACITY(*lOut) = CAPACITY(lIn);
    NEFF(*lOut) = NEFF(lIn);
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
ElType sumList(ListDin l) {
    ElType sum = 0, i;
    for (i = IDX_MIN; i < listLength(l); i++) {
        sum += ELMT(l, i);
    }
    return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val) {
    int n = 0, i;
    for (i = IDX_MIN; i < listLength(l); i++) {
        if (val == ELMT(l, i)) {
            n += 1;
        }
    }
    return n;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc) {
    int i, j, temp;
    for (i = IDX_MIN; i < listLength(*l); i++) {
        for (j = i; j < listLength(*l); j++) {
            if (asc) {
                if (ELMT(*l, i) > ELMT(*l, j)) {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, i);
                    ELMT(*l, i) = temp;
                }
            }
            else {
                if (ELMT(*l, i) < ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val) {
    if (isEmpty(*l)) {
        NEFF(*l) = 1;
    }
    else {
        NEFF(*l) += 1;
    }
    ELMT(*l, NEFF(*l) - 1) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val) {
    *val = ELMT(*l, NEFF(*l) - 1);
    NEFF(*l) -= 1;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num) {
    CAPACITY(*l) += num;
    BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num) {
    CAPACITY(*l) -= num;
    BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l){
    CAPACITY(*l) = listLength(*l);
    BUFFER(*l) = realloc(BUFFER(*l), CAPACITY(*l) * sizeof(ElType));

}



//int main() {
//    ListDin l1;
//    CreateListDin(&l1, 12);
//    readList(&l1);
//    printList(l1);
//    return 0;
//}