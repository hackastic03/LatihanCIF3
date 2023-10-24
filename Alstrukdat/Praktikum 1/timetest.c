#include <stdio.h>
#include "../../Pra-Praktikum/Praktikum 1/time.c"

int main() {
    TIME t1, t2;
    BacaTIME(&t1);
    BacaTIME(&t2);
    TulisTIME(NextDetik(t1));
    printf("\n%ld %ld \n", Durasi(t1, t2), TIMEToDetik(t2));
    int x;
    TulisTIME(PrevNDetik(t2, 20));

//printf("%ld", ((86400 - 16) % 86400) /3600);
}
