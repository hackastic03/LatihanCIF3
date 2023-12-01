#include "utas.h"
#include <stdio.h>
#include <stdlib.h>
#include "../ADT_Boolean/boolean.h"
//#include "../../Functions/kicauan/newlistdin.h"
//#include "../../Functions/kicauan/datetime.c"

ArrayUtas arrayofUtas;
ListDin List_Kicauan;
User currentUser;


void initializeUtas() {
    arrayofUtas.nEff = 0;
    arrayofUtas.buffer = (Utas*) malloc(sizeof(Utas) * 10000);
    int i;
    for (i = 0; i < 10000; i++) {
        arrayofUtas.buffer[i].utasTop = NULL;
    }
    arrayofUtas.capacity = 10000;
}


char* getTime() {
    char* waktu = (char *)malloc(sizeof(char) * 200);
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(waktu, 200, "%d/%m/%Y %H:%M:%S", info);
    return waktu;
}


void splitWordUtas(Word Command, Word* stringCommand, int *idKicau, int *idUtas) {
    int i = 0;
    while (Command.TabWord[i] != ' ' && i < Command.Length) {
        stringCommand->TabWord[i] = Command.TabWord[i];
        i++;
    }
    stringCommand->Length = i;
    i++; // Menghilangkan spasi
    *idKicau = 0;
    while (i < Command.Length) {
        *idKicau = *idKicau * 10 + (Command.TabWord[i] - '0');
        i++;
        if (Command.TabWord[i] == ' ') {
            break;
        }
    }
    if (i < Command.Length) {
        i++;
        *idUtas = 0;
        while (i < Command.Length) {
            *idUtas = *idUtas * 10 + (Command.TabWord[i] - '0');
            i++;
        }
    }
}


int stringCompareWord(Word Command, char* Input) {
    int i = 0;
    while (i < Command.Length && Input[i] != '\0') {
        if (Command.TabWord[i] != Input[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}


DATETIME getDATETIME() {
    time_t seconds = time(NULL);
    return DetikToDATETIME(seconds);
}



int lengthUtas(User User, int idUtas) {
    int count = 0;
    AddressUtas P = arrayofUtas.buffer[idUtas].utasTop;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}


int lengthArrayUtas() {
    return arrayofUtas.nEff;
}


boolean isUtasAlreadyExist(User User, int idKicau) {
    int i, length = lengthArrayUtas();
    for (i = 0; i < length; i++) {
        if (arrayofUtas.buffer[i].kicauanUtama.ID == idKicau) {
            return true;
        }
    }
    return false;
}


AddressUtas newUtas(User User, Word Isi) {
    AddressUtas P = (AddressUtas) malloc(sizeof(NodeUtas));
    if (P != NULL) {
        P->isi = Isi;
        P->time = getTime();
        P->next = NULL;
    }
    return P;
}


void BuatUtas(User User, int idKicau) {
    if (getLastIdx(List_Kicauan) < idKicau) {
        printf("Kicauan tidak ditemukan\n");
        return;
    }
    if (isUtasAlreadyExist(User, idKicau)) {
        printf("Utas sudah ada untuk indeks kicauan tersebut\n");
        return;
    }
    if (!isWordEqual(List_Kicauan.buffer[idKicau].author, User.username)) { // Nanti ganti jadi user.id
        printf("Utas ini bukan milik Anda!\n");
        return;
    }

    printf("Utas berhasil dibuat!\n\n");
    Word Isi;
    printf("Masukkan kicauan:\n");
    STARTSENTENCE();
    Isi = CopyToNewWord(currentWord);
    AddressUtas P = newUtas(User, Isi);
    arrayofUtas.buffer[arrayofUtas.nEff].kicauanUtama = List_Kicauan.buffer[idKicau];
    arrayofUtas.buffer[arrayofUtas.nEff].idArrayKicau = idKicau;
    arrayofUtas.buffer[arrayofUtas.nEff].utasTop = P;
    arrayofUtas.buffer[arrayofUtas.nEff].user = User;
    arrayofUtas.buffer[arrayofUtas.nEff].banyakUtas = 1;
    arrayofUtas.nEff++;

    printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
    Word valid;
    STARTSENTENCE();
    valid = CopyToNewWord(currentWord);
    if (stringCompareWord(valid, "TIDAK")) {
        printf("Utas selesai!\n\n");
        return;
    }
    boolean inUtas = true;
    while (inUtas) {
        printf("Masukkan kicauan:\n");
        STARTSENTENCE();
        Isi = CopyToNewWord(currentWord);
        AddressUtas new = newUtas(User, Isi);
        AddressUtas First = arrayofUtas.buffer[arrayofUtas.nEff - 1].utasTop;
        while (NEXT(First) != NULL) {
            First = NEXT(First);
        }
        NEXT(new) = NEXT(First);
        NEXT(First) = new;
        arrayofUtas.buffer[arrayofUtas.nEff - 1].banyakUtas++;
        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)");
        STARTSENTENCE();
        valid = CopyToNewWord(currentWord);
        if (stringCompareWord(valid, "TIDAK")) {
            printf("Utas selesai!\n\n");
            inUtas = false;
        }
    }
}


void SambungUtas(User User, int idUtas, int idArrayUtas) {
    if (getLastIdx(List_Kicauan) < idArrayUtas) {
        printf("Kicauan tidak ditemukan\n\n");
        return;
    }
    if (!isUtasAlreadyExist(User, idArrayUtas)) {
        printf("Utas tidak ditemukan!\n\n");
        return;
    }
    if (!isWordEqual(List_Kicauan.buffer[idArrayUtas].author, User.username)) {
        printf("Anda tidak bisa menyambung utas ini!\n\n");
        return;
    }
    if (idUtas > arrayofUtas.buffer[idArrayUtas].banyakUtas) {
        printf("Indeks terlalu tinggi!\n\n");
        return;
    }
    printf("Masukkan kicauan:\n");
    Word isi;
    STARTSENTENCE();
    isi = CopyToNewWord(currentWord);
    AddressUtas P = newUtas(User, isi);
    if (idUtas == 0) {
        NEXT(P) = arrayofUtas.buffer[idArrayUtas].utasTop;
        arrayofUtas.buffer[idArrayUtas].utasTop = P;
        arrayofUtas.buffer[idArrayUtas].banyakUtas++;
    }
    else {
        AddressUtas First = arrayofUtas.buffer[idArrayUtas].utasTop;
        int i;
        for (i = 0; i < idUtas - 1; i++) {
            First = NEXT(First);
        }
        NEXT(P) = NEXT(First);
        NEXT(First) = P;
        arrayofUtas.buffer[idArrayUtas].banyakUtas++;
    }
}


void HapusUtas(User User, int idUtas, int idArrayUtas) {
    if (idArrayUtas > arrayofUtas.nEff) {
        printf("Utas tidak ditemukan!\n\n");
        return;
    }
    if (idUtas > arrayofUtas.buffer[idArrayUtas].banyakUtas) {
        printf("Indeks terlalu tinggi!\n\n");
        return;
    }
    if (!isWordEqual(List_Kicauan.buffer[idArrayUtas].author, User.username)) {
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n\n");
        return;
    }
    Word isi;
    STARTSENTENCE();
    isi = CopyToNewWord(currentWord);
    if (idUtas == 0) {
        printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n\n");
    }
    if (idUtas == 1) {
        AddressUtas P = arrayofUtas.buffer[idArrayUtas].utasTop;
        arrayofUtas.buffer[idArrayUtas].utasTop = NEXT(P);
        free(P);
    }
    else {
        AddressUtas First = arrayofUtas.buffer[idArrayUtas].utasTop;
        int i;
        for (i = 0; i < idUtas - 1; i++) {
            First = NEXT(First);
        }
        AddressUtas P = NEXT(First);
        NEXT(First) = NEXT(P);
        free(P);
    }
    arrayofUtas.buffer[idArrayUtas].banyakUtas--;
}


void CetakUtas(User User, int idArrayUtas) {
    idArrayUtas--;
    AddressUtas P = arrayofUtas.buffer[idArrayUtas].utasTop;
    // Print kicauan utama
    printf("| ID = %d\n", arrayofUtas.buffer[idArrayUtas].kicauanUtama.ID);
    printf("| %s\n", arrayofUtas.buffer[idArrayUtas].kicauanUtama.author.TabWord);
    printf("| ");
    TulisDATETIME(List_Kicauan.buffer[arrayofUtas.buffer[idArrayUtas].idArrayKicau].datetime);
    printf("\n");
    printf("| %s\n", List_Kicauan.buffer[arrayofUtas.buffer[idArrayUtas].idArrayKicau].text.TabWord);
    // Print utas
    int idUtas = 1;
    while (P != NULL) {
        printf("    | INDEX = %d\n", idUtas);
        printf("    | %s\n", arrayofUtas.buffer[idArrayUtas].user.username.TabWord);
        printf("    | %s\n", P->time);
        printf("    | %s\n\n", P->isi.TabWord);
        P = P->next;
        idUtas++;
    }
}


void saveUtastoConfig(User User, Word FolderPath) {
    char* folder = FolderPath.TabWord;
    char* file = "/utas.config";
}


int main() {
    initializeUtas();
    CreateListDin(&List_Kicauan, 10000);
    currentUser.id = 1;
    currentUser.username.TabWord[0] = 'a';
    currentUser.username.TabWord[1] = 'b';
    currentUser.username.TabWord[2] = 'c';

    while (true) {
        printf("Masukkan perintah: ");
        Word command;
        STARTSENTENCE();
        command = CopyToNewWord(currentWord);
        int idKicau, idUtas;
        Word splitCommand;
        splitWordUtas(command, &splitCommand, &idKicau, &idUtas);
        if (stringCompareWord(splitCommand, "KICAU")) {
            printf("username: %s\n", currentUser.username.TabWord);
            Tweet(&List_Kicauan, currentUser.username);
        }
        else if (stringCompareWord(splitCommand, "UTAS")) {
            BuatUtas(currentUser, idKicau);
        } else if (stringCompareWord(splitCommand, "SAMBUNG_UTAS")) {
            SambungUtas(currentUser, idKicau, idUtas);
        } else if (stringCompareWord(splitCommand, "CETAK_UTAS")) {
            CetakUtas(currentUser, idKicau);
        }
        else {
            printf("Maaf, perintah tidak dikenali.\n");
        }
    }
}