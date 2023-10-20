#include <stdio.h>
#include "stack.h"
#include "charmachine.h"
#include "wordmachine.h"
// #include "stack.c"


int chartoint(char c) {
    return c - '0';
}

int main() {
    Stack num;
    CreateEmpty(&num);
    int i;
    long long int temp;

    STARTWORD();
    // Angka pertama
    long long int a = 0;
    for (i = 0; i < currentWord.Length; i++) {
        temp = chartoint(currentWord.TabWord[i]);
        Push(&num, temp);
    }
    int pengali = 1;
    
    while (!IsEmpty(num)) {
        Pop(&num, &temp);
        a += temp * pengali;
        pengali *= 10;
    }
    ADVWORD();

    // Angka kedua
    long long int b = 0;
    for (i = 0; i < currentWord.Length; i++) {
        temp = chartoint(currentWord.TabWord[i]);
        Push(&num, temp);
    }
    pengali = 1;
    while (!IsEmpty(num)) {
        Pop(&num, &temp);
        b += temp * pengali;
        pengali *= 10;
    }

    printf("%lld\n", a-b);

    return 0;
}