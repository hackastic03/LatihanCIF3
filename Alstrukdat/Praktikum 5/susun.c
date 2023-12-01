#include "wordmachine.h"
#include <stdio.h>
#include "boolean.h"

void printWord(Word word) {
    int i;
    for (i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}

boolean compareWord(Word Word1, Word Word2) {
    int i;
    if (Word1.Length < Word2.Length) {
        for (i = 0; i < Word1.Length; i++) {
            if (Word1.TabWord[i] < Word2.TabWord[i]) {
                return true;
            } else if (Word1.TabWord[i] > Word2.TabWord[i]) {
                return false;
            }
        }
        return true;
    } else {
        for (i = 0; i < Word2.Length; i++) {
            if (Word1.TabWord[i] < Word2.TabWord[i]) {
                return true;
            } else if (Word1.TabWord[i] > Word2.TabWord[i]) {
                return false;
            }
        }
        return false;
    }
}

int main() {
    int i = 0, j;
    Word kata[100];
    boolean sort;
    Word current;
    STARTWORD();
    while (!EndWord) {
        kata[i].Length = currentWord.Length;
        for (j = 0; j < currentWord.Length; j++) {
            kata[i].TabWord[j] = currentWord.TabWord[j];
        }
        i++;
        ADVWORD();
    }

    sort = false;
    while (!sort) {
        sort = true;
        for (j = 0; j < i-1; j++) {
            if (compareWord(kata[j+1], kata[j]) == true) {
                current = kata[j];
                kata[j] = kata[j+1];
                kata[j+1] = current;
                sort = false;
            }
        }
    }
    for (j = 0; j < i; j++) {
        printWord(kata[j]);
        printf("\n");
    }
    return 0;
}