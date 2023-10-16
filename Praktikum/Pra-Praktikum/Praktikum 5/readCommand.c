#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include <stdio.h>
//#include "charmachine.c"
//#include "wordmachine.c"


void printWord(Word word) {
    int i;
    for (i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}



int main() {
    Word word;
    START();
    IgnoreBlanks();
    int n = 0;
    while (currentChar != MARK) {
        printf("%c", currentChar);
        n += 1;
        ADV();
    }
    printf("\n");
    printf("%d\n", n);


    return 0;
}