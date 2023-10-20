#include <stdio.h>
//#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
// #include "charmachine.c"
// #include "wordmachine.c"


int stringLength(char *s) {
    int result =  0;
    int i = 0;
    while (s[i] != '\0') {
        ++result;
        ++i;
    }
    return result;
}

int main(){
    int n;
    scanf("%d", &n);
    STARTWORD();
    if(currentWord.Length == stringLength("MOVEUP")) {
        printf("Moving %d square upwards\n",n);
    }
    else if(currentWord.Length == stringLength("MOVERIGHT")) {
        printf("Moving %d square rightwards\n",n);
    }
    else {
        currentChar = currentWord.TabWord[currentWord.Length-2];
        if(currentChar == 'F') {
            printf("Moving %d square leftwards\n",n);
        }
        else {
            printf("Moving %d square downwards\n",n);
        }
    }
}
