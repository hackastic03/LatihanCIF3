#include "draf.h"
#include <time.h>
DrafUser ListDraf[CAPACITYPENGGUNA];
ListDin List_Kicauan;
// Jangan lupa untuk CreateListDin dari fungsi kicauan.c agar gak segmentation fault

void convertIntCharSaveConfig(int num, FILE *fp) {
    char c;
    while (num > 0) {
        c = num % 10 + '0';
        fputc(c, fp);
        num /= 10;
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


void initializeDraftArray() { // Digunakan untuk inisialisasi bahwa semua draft awalnya kosong
    int i;
    for (i = 0; i < CAPACITYPENGGUNA; i++) {
        ListDraf[i].List.drafTop = NULL;
    }
}


AddressDraf newDraft(User person, Word Isi) {
    AddressDraf P = (AddressDraf) malloc(sizeof(NodeDraf));
    if (P != NULL) {
        ISI(P) = Isi;
        NEXT(P) = NULL;
        TIME(P) = getTime();
    }
    return P;
}


boolean isDraftEmpty(User person) {
    return ListDraf[person.id].List.drafTop == NULL;
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


int lengthDraft(User person) {
    if (isDraftEmpty(person)) {
        return 0;
    }
    else {
        int length = 0;
        AddressDraf P = ADDR_TOP(ListDraf[person.id].List);
        while (P != NULL) {
            length++;
            P = NEXT(P);
        }
        return length;
    }
}


int arrayofDraftUser() {
    int i;
    int count = 0;
    for (i = 0; i < CAPACITYPENGGUNA; i++) {
        if (ListDraf[i].List.drafTop != NULL) {
            count++;
        }
    }
    return count;
}


AddressDraf topDraft(User person) {
    return ListDraf[person.id].List.drafTop;
}


void addDraft(User User) {
    Word isiDraf;
    printf("Masukkan draf:\n");
    STARTSENTENCE();
    isiDraf = CopyToNewWord(currentWord);
    AddressDraf p = newDraft(User, isiDraf);
    Word newCommand;
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    STARTSENTENCE();
    newCommand = CopyToNewWord(currentWord);
    if (stringCompareWord(newCommand, "TERBIT")) {
        publishDraft(User, isiDraf);
    }
    else if (stringCompareWord(newCommand, "SIMPAN")) {
        saveDraft(User, p);
        return;
    }
    else if (stringCompareWord(newCommand, "HAPUS")) {
        deleteDraft(User);
    }
    else {
        printf("Maaf, perintah tidak dikenali.\n");
    }
}


void publishDraft(User person, Word isi) {
    printf("Masukkan hashtag: \n");
    Word tagar;
    STARTSENTENCE();
    tagar = CopyToNewWord(currentWord);
    time_t second;
    second = time(NULL);
    DateTime(List_Kicauan.buffer[NEFF(List_Kicauan)]) = DetikToDATETIME(second);
    LIKE(List_Kicauan.buffer[NEFF(List_Kicauan)]) = 0;
    AUTHOR(List_Kicauan.buffer[NEFF(List_Kicauan)]) = person.username;
    TAG(List_Kicauan.buffer[NEFF(List_Kicauan)]) = tagar;
    ID_NUM(List_Kicauan.buffer[NEFF(List_Kicauan)]) = NEFF(List_Kicauan) + 1;
    TWEET(List_Kicauan.buffer[NEFF(List_Kicauan)]) = isi;
    NEFF(List_Kicauan) += 1;
    printf("\nSelamat! Kicauan telah diterbitkan!\nDetail kicauan:\n");
    printTweet(List_Kicauan, getLastIdx(List_Kicauan));
}


void editDraft(User User) {
    Word isi;
    printf("Masukkan draf yang baru:\n");
    STARTSENTENCE();
    isi = CopyToNewWord(currentWord);
    ListDraf[User.id].List.drafTop->isi = isi;
    ListDraf[User.id].List.drafTop->time = getTime();
    Word newCommand;
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    STARTSENTENCE();
    newCommand = CopyToNewWord(currentWord);
    if (stringCompareWord(newCommand, "TERBIT")) {
        publishDraft(User, isi);
    }
    else if (stringCompareWord(newCommand, "SIMPAN")) {
        printf("Draf telah berhasil disimpan!\n");
        return;
    }
    else if (stringCompareWord(newCommand, "HAPUS")) {
        deleteDraft(User);
    }
    else {
        printf("Maaf, perintah tidak dikenali.\n");
    }
}


void saveDraft(User User, AddressDraf P) {
    AddressDraf Q = newDraft(User, P->isi);
    if (Q != NULL) {
        NEXT(Q) = ADDR_TOP(ListDraf[User.id].List);
        (ListDraf[User.id].List.drafTop) = Q;
    }
    ListDraf[User.id].User = User;
    printf("Draf telah berhasil disimpan!\n");
}


void deleteDraft(User person) {
    AddressDraf P = ListDraf[person.id].List.drafTop;
    ListDraf[person.id].List.drafTop = NEXT(P);
    free(P);
    printf("Draf telah berhasil dihapus!\n");
}


void displayDraft(User person) {
    if (isDraftEmpty(person)) {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
    else {
        printf("Ini draf terakhir anda:\n");
        printf("| %s\n", ListDraf[person.id].List.drafTop->time);
        printf("| %s\n", ListDraf[person.id].List.drafTop->isi.TabWord);
    }
    Word newCommand;
    printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
    STARTSENTENCE();
    newCommand = CopyToNewWord(currentWord);
    if (stringCompareWord(newCommand, "UBAH")) {
        editDraft(person);
    }
    else if (stringCompareWord(newCommand, "HAPUS")) {
        deleteDraft(person);
    }
    else if (stringCompareWord(newCommand, "TERBIT")) {
        publishDraft(person, ListDraf[person.id].List.drafTop->isi);
    }
    else if (stringCompareWord(newCommand, "KEMBALI")) {
        return;
    }
    else {
        printf("Maaf, perintah tidak dikenali.\n");
    }
}


void saveDraftConfig(User person) {
    FILE *file;
    file = fopen("draf.config", "w");
    if (file == NULL) {
        printf("File tidak dapat dibuka!\n");
    }
    convertIntCharSaveConfig(arrayofDraftUser(), file);
    fputc('\n', file);
    int i;
    for (i = 0; i < CAPACITYPENGGUNA; i++) {
        if (ListDraf[i].List.drafTop == NULL) {
            continue;
        }
        else {
            fputs(ListDraf[i].User.username.TabWord, file);
            fputs(" ", file);
            convertIntCharSaveConfig(lengthDraft(ListDraf[i].User), file);
            fputc('\n', file);

            AddressDraf P = ListDraf[i].List.drafTop;
            while (P != NULL) {
                fputs(P->isi.TabWord, file);
                fputs("\n", file);
                fputs(P->time, file);
                fputc('\n', file);
                P = NEXT(P);
            }
        }
        fclose(file);
    }
}


void loadDraftConfig(char* filename) {
    FILE *file;
    char CONTENT[MAX_CHAR];
    int row = 0, i;
    int maxUser = 0, userNow = 0;
    while (fgets(CONTENT, MAX_CHAR, file) != NULL) {
        if (row == 0) {
            maxUser = atoi(CONTENT);
        }
        else {

        }
        row++;
    }
}

