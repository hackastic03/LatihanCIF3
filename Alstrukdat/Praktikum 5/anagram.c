#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"


int isAnagram(char* Word1, char* Word2) {
    int string[26] = {0};
    int i = 0;
    for (i = 0; Word1[i] != '\0'; i++) {
        string[Word1[i] - 'a']++;
    }
    for (i = 0; Word2[i] != '\0'; i++) {
        string[Word2[i] - 'a']--;
    }

    for (i = 0; i < 26; i++){
        if (string[i] != 0) {
            return 0;
        }
    }
    return 1;
}


int main() {
    STARTWORD();

    char word[100][100]; // Maksimal 100 word dengan masing-masing panjang maksimal 20
    int countWord = 0;

    while (!EndWord) {
        if (countWord < 100) {
            for (int i = 0; i < currentWord.Length; i++) {
                word[countWord][i] = currentWord.TabWord[i];
            }
            word[countWord][currentWord.Length] = '\0';
            countWord++;
        }
        ADVWORD();
    }

    int jumlahAnagram = 0;
    int i, j;
    for (i = 0; i < countWord; i++) {
        for (j = i + 1; j < countWord; j++) {
            if (isAnagram(word[i], word[j])) {
                jumlahAnagram++;
            }
        }
    }
    printf("%d\n", jumlahAnagram);
}
