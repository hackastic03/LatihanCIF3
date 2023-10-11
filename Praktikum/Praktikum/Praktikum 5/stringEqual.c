#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
// #include "charmachine.c"
// #include "wordmachine.c"

boolean EndWord;
Word currentWord;
char currentChar;
int stringLength(char *s);
void printWord(Word word) {

   int i;

   for (i = 0; i < word.Length; i++) {

      printf("%c", word.TabWord[i]);

   }

}

int main() {
    int n;
    n = scanf("%d", &n);
    char up[] = "MOVEUP";
    char down[] = "MOVEDOWN";
    char left[] = "MOVELEFT";
    char right[] = "MOVERIGHT";
    IgnoreBlanks();
    STARTWORD();
    int i = 0;
    while ((currentChar != MARK) && currentChar != BLANK) {
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

    if (currentWord.Length == stringLength("MOVEUP")) {
        printf("Moving %d square upwards\n", n);
    }
    else if (currentWord.Length == stringLength("MOVERIGHT")) {
        printf("Moving %d square rightwards\n", n);
    }
    else {
        if (currentWord.TabWord[currentWord.Length - 2] == "F") {
            printf("Moving %d square leftwards\n", n);
        }
        else {
            printf("Moving %d square downwards\n", n);
        }
    }


    


    

}



int stringLength(char *s) {

   int result =  0;

   int i = 0;

   while (s[i] != '\0') {

      ++result;

      ++i;

   }

   return result;

}

