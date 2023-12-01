#include <stdio.h>
#include "list_circular.h"

int main() {
    int N, i , j , step;
    Address player, left, out;
    List l;
    CreateList(&l);
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        insertLast(&l, i + 1);
    }
    player = FIRST(l);
    while (NEXT(player) != FIRST(l)) {
        player = NEXT(player);
    }
    left = player;
    player = NEXT(left);

    i = 0;
    scanf("%d", &step);
    while(i < N - 1) {
        while(step < 0) {
            step += N - i;
        }
        for(j = 0; j < step; j++) {
            player = NEXT(player);
            left = NEXT(left);
        }
        NEXT(left) = NEXT(player);
        out = player;
        player = NEXT(player);
        deallocate(out);
        if(i < N - 2) {
            scanf("%d", &step);
            if(step > 0) {
                step--;
            }
        }
        i++;
    }
    printf("%d\n", INFO(player));
    return 0;
}