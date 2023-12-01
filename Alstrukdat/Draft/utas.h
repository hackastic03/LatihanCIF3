#ifndef UTAS_H
#define UTAS_H

#include <stdio.h>
#include <stdalign.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT_MesinKata/mesinkata.h"
#include "../ADT_User/user.h"
#include "../ADT_Boolean/boolean.h"
//#include "../ADT_Profile/profile.h"
#include "../../Functions/kicauan/kicauan.c"

typedef struct nodeUtas* AddressUtas;

// Setiap node pada utas, linked list
typedef struct nodeUtas {
    Word isi;
    char* time;
    AddressUtas next;
} NodeUtas;

// Utas dan kicauan utamanya
typedef struct {
    AddressUtas utasTop; // Menunjuk ke utas paling pertama
    User user;
    kicauan kicauanUtama;
    int banyakUtas;
    int idArrayKicau; // Indeks kicauan pada array of kicauan (listdin kicauan) yang menjadi kicauan utama
} Utas;


// Array of utas, list dinamis
typedef struct {
    Utas *buffer; // Utas disimpan berdasarkan id array utas
    int nEff;
    int capacity;
} ArrayUtas;


/* Secara struktur utas sebagai berikut:
 * ArrayUtas berisi kumpulan utas (layaknya ListDin pada kicauan), dapat diakses buffer-nya,
 * dan tiap indeks berisi Utas (yang dimulai dari utasTop yang berindeks 1) yang merupakan LinkedList
 * Utas adalah LinkedList yang memiliki FIRST yaitu utasTop dan berisi User sebagai pemilik
 * utas dan idArrayKicau yang merupakan indeks kicauan utama pada array of kicauan.
 * utasTop akan menunjuk next ke nodeUtas yang berisi utas selanjutnta. utasTop memiliki indeks 1
 * dan kicauanUtama dianggap sebagai indeks 0 (manual integration)
 */


#define NEXT(p) (p)->next

// Memecah command yang di-input dan indeks yang dimasukkan. Khusus untuk buat_utas dan cetak_utas
void splitWordUtas(Word Command, Word* stringCommand, int *idKicau, int *idUtas);

int stringCompareWord(Word Command, char* Input);

DATETIME getDATETIME();

void initializeUtas();

AddressUtas newUtas(User User, Word Isi);

int lengthUtas(User User, int idKicau);

// Melihat
void BuatUtas(User User, int idKicau);

void SambungUtas(User User, int idUtas, int idKicau);

void HapusUtas(User User, int idUtas, int idKicau);

void CetakUtas(User User, int idArrayUtas);

char* getTime();

void saveUtastoConfig(User User, Word FolderPath);

#endif