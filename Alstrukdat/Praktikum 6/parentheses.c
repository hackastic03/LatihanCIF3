#include "stack.h"
#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

void readWord(Word *input) {
    int i;
    START();
    IgnoreBlanks();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}


int main() {
    Word word;
    readWord(&word);
    int depth = 0, kurungbuka = 0, kurungtutup = 0, i, maxdepth = 0;

    for (i = 0; i < word.Length; i++) {
        if (word.TabWord[i] == '(') {
            depth++;
            kurungbuka++;
        }
        if (word.TabWord[i] == ')') {
            if (depth > maxdepth) {
                maxdepth = depth;
            }
            depth--;
            kurungtutup++;
        }
    }

    if (kurungbuka != kurungtutup) {
        printf("-1\n");
    }
    else {
        printf("%d\n", maxdepth);
    }
}