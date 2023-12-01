#ifndef DRAF_H
#define DRAF_H

#include "../ADT_Boolean/boolean.h"
#include "../ADT_User/User.h"
#include "../ADT_MesinKata/mesinkata.h"
#include <time.h>
#include "../ADT_User/User.h"
#include <stdio.h>
#include <stdlib.h>
#include "../ADT_MesinKata/mesinkata.h"
#include "../ADT_MesinKar/mesinkar.h"
#include "../../Functions/kicauan/kicauan.c"
//#include "../ADT_MesinKar/mesinkar.c"
//#include "../ADT_MesinKata/mesinkata.c"

#define MAX_CHAR 280


typedef struct nodeDraf* AddressDraf;
typedef struct nodeDraf {
    Word isi;
    AddressDraf next;
    char* time;
} NodeDraf;

typedef struct {
    AddressDraf drafTop;
} Draf;

typedef struct {
    Draf List;
    User User;
} DrafUser;

#define ADDR_TOP(p) (p).drafTop
#define TOP_ISI(p) (p).drafTop->isi
#define TOP_TIME(p) (p).drafTop->t
#define ISI(p) (p)->isi
#define NEXT(p) (p)->next
#define TIME(p) (p)->time

int stringCompareWord(Word Command, char* Input);

void initializeDraftArray();

AddressDraf newDraft(User User, Word Isi);

boolean isDraftEmpty(User User);

int lengthDraft(User person);

char* getTime();

AddressDraf topDraft(User User);

void publishDraft(User User, Word isi);

void addDraft(User User);

void saveDraft(User User, AddressDraf P);

void editDraft(User User);

void deleteDraft(User User);

void displayDraft(User User);

void saveDraftConfig(User User);

void loadDraftConfig(char* filename);

#endif