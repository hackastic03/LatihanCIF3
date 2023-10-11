#include <stdio.h>
#include "stack.h"
#include "charmachine.h"
#include "wordmachine.h"
// #include "stack.c"

Word copy() {

}




int main() {
    Word listWords[100];
    int countWord = 0;
    Stack num1, num2;
    CreateEmpty(&num1);
    CreateEmpty(&num2);
    int id = 1;
    int s1, s2;
    s1 = 0, s2 = 0;

    START();
    while(currentChar != MARK){
        int j;
        if (currentChar == BLANK) {
            if (id == 2) {
                s2 / 10;
            }
            if (id == 1) {
                s1 / 10;
                id = 2;
            }
        }
        ADVWORD();
        
        listWords[countWord] = currentWord;
        if (id == 1) {
            Push(&num1, currentChar);
            s1 += (currentChar - '0') * 10;
        }
        else if (id == 2) {
            Push(&num2, currentChar);
            s2 += (currentChar - '0') * 10;
        }
        countWord++;
    }

    printf("%d\n", s1 - s2);



}