#include <stdio.h>
#include "stack.h"
#include "charmachine.h"
#include "wordmachine.h"
// #include "stack.c"


int chartoint(char c) {
    return c - '0';
}

int main() {
    Word listWords[100];
    int countWord = 0;
    START();
    while(currentChar != MARK){
        ADVWORD();
        listWords[countWord] = currentWord;
        countWord++;
    }
    Stack S;
    CreateEmpty(&S);
    int i,j;
    int diff = listWords[0].Length - listWords[1].Length;
    for(i=0; i<listWords[0].Length;i++){
        if(i < diff){
            int convert = chartoint(listWords[0].TabWord[i]);
            Push(&S,convert);
        } else{
            int convert = (chartoint(listWords[0].TabWord[i])) - (chartoint(listWords[1].TabWord[i-diff]));
            Push(&S, convert);
        }
    }
    Stack Srefersed;
    CreateEmpty(&Srefersed);
    boolean carry = false;
    while(!IsEmpty(S)){
        int temp;
        Pop(&S,&temp);
        if(carry){
            temp--;
            carry = false;
        }
        if(temp < 0){
            temp += 10;
            carry = true;
        }
        Push(&Srefersed,temp);
    }

    i = 0;
    while(InfoTop(Srefersed) == 0 && i < listWords[0].Length-1){
        int temp;
        Pop(&Srefersed, &temp);
        i++;
    }

    while(!IsEmpty(Srefersed)){
        int temp;
        Pop(&Srefersed,&temp);
        printf("%d",temp);
    }
    printf("\n");
}