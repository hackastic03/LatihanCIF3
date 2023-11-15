#include <stdio.h>

void Metropolis() {
    int a, b;
    scanf("%d", &a);
    if (a < 1 || a > 9) {
        illegal_move();
    }
    scanf("%d", &b);
    switch (a) {
        case 1:
            if (b != 391) {
                illegal_move();
            }
        case 2:
            if (b != 391) {
                illegal_move();
            }
        case 3:
            if (b != 760) {
                illegal_move();
            }
        case 4:
            if (b != 1037) {
                illegal_move();
            }
        case 5:
            if (b != 753){
                illegal_move();
            }
        case 6:
            if (b != 284) {
                illegal_move();
            }
        case 7:
            if (b != 62) {
                illegal_move();
            }
        case 8:
            if (b != 505) {
                illegal_move();
            }
        case 9:
            if (b != 62) {
                illegal_move();
            }
    }
    return;
}