#include "boolean.h"
#include <stdio.h>
#include "wordmachine.h"
#include <stdlib.h>
// #include "charmachine.c"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    while (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    }
    else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
//    printf("test");
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax) {
        currentWord.Length = NMax;
    }
    else {
        currentWord.Length = i;
    }
}