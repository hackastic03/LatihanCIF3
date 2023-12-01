#include <stdio.h>
#include "boolean.h"
#include "stacklinked.h"

int main() {
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++){
        int n, j;
        Stack utama, kecil;
        CreateStack(&utama);
        CreateStack(&kecil);
        scanf("%d", &n);
        int target = 1;
        for(j = 0; j < n; j++){
            if(!isEmpty(kecil)){
                boolean stop = false;
                while(!isEmpty(kecil) && !stop){
                    if(TOP(kecil) == target){
                        int temp;
                        pop(&kecil, &temp);
                        push(&utama, temp);
                        target++;
                    } 
                    else {
                        stop = true;
                    }
                }
            }
            int p;
            scanf("%d", &p);
            if (p == target){
                push(&utama, p);
                target ++;
            } 
            else{
                push(&kecil, p);
            }
        }
        while (!isEmpty(kecil)) {
            int temp;
            pop(&kecil, &temp);
            push(&utama, temp);
        }
        boolean done = true;
        while (length(utama) != 1 && done){
            int top;
            pop(&utama, &top);
            if(TOP(utama) > top){
                done = false;
            }
        }
        if(done) {
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    return 0;
}