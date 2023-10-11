#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
// #include "charmachine.c"
// #include "wordmachine.c"

boolean EndWord;
Word currentWord;


int main() {
    START();

    int i = 0;
    while ((currentChar != MARK)) {
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

    printWord(currentWord);
    printf("\n");
    printf("%d\n", i);

}

// Prints word from Mesin Kata
int printWord(Word word) {

   int i;

   for (i = 0; i < word.Length; i++) {

      printf("%c", word.TabWord[i]);

   }

}