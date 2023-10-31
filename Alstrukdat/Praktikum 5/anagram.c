#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"
//#include "charmachine.c"
//#include "charmachine.c"

int main() {
    Word words[100];
    int wordCount = 0;
    int i, j, k;
    int anagram = 0;
    STARTWORD();
    while (!EndWord) {
        words[wordCount] = currentWord;
        wordCount++;
        ADVWORD();
    }
    for (i = 0; i < wordCount; i++) {
        for (j = i + 1; j < wordCount; j++) {
            if (words[i].Length == words[j].Length) {
//                boolean isAnagram = true;
//                for (k = 0; k < words[i].Length; k++) {
//                    if (words[i].TabWord[k] != words[j].TabWord[k]) {
//                        isAnagram = false;
//                        break;
//                    }
//                }
                int s = 0, r;
                int a = 0, b = 0;
                while (s < words[i].Length) {
                    a = 0, b = 0;
                    char temp = words[i].TabWord[s];
                    // Cek jumlah huruf temp di kata pertama
                    for (r = 0; r < words[i].Length; r++) {
                        if (temp == words[i].TabWord[r]) {
                            a++;
                        }
                    }
                    for (r = 0; r < words[j].Length; r++) {
                        if (temp == words[j].TabWord[r]) {
                            b++;
                        }
                    }
                    s++;
                }
                if (a == b) {
                    anagram++;
                }
            }
        }
    }
    printf("%d\n", anagram);
}
