#include <stdio.h>
#include "time.h"
#include <math.h>

void tuliswaktu(TIME t) {
    printf("%d:%d:%d\n", Hour(t), Minute(t), Second(t));
}

int main() {
    int n, i;
    long selisih1 = 0;
    long selisih2 = 0;
    TIME tmax, tmin, t1, t2, t3, t4;
    scanf("%d", &n);
    printf("[%d]\n", 1);
    BacaTIME(&t3);
    BacaTIME(&t4);
    if (TGT(t3, t4)) {
        tmax = t3;
        tmin = t4;
        selisih2 = Durasi(t4, t3);
    }
    else {
        tmax = t4;
        tmin = t3;
        selisih2 = Durasi(t3, t4);
    }
    printf("%ld\n", selisih2);

    for(i = 2; i <= n; i++) {
        printf("[%d]\n", i);
        BacaTIME(&t1);
        BacaTIME(&t2);
        if (TGT(t1, t2)) {
            selisih1 = Durasi(t2, t1);
        }
        else {
            selisih1 = Durasi(t1, t2);
        }
        printf("%ld\n", selisih1);
        if (TGT(t1, tmax) && TGT(t1, t2)) {
            tmax = t1;
        }
        else if (TGT(t2, tmax) && TGT(t2, t1)) {
            tmax = t2;
        }
        else if (TEQ(t1, t2) && (TGT(t1, tmax))) {
            tmax = t1;
        }
        if (TLT(t1, tmin) && TLT(t1, t2)) {
            tmin = t1;
        }
        else if (TLT(t2, tmin) && TLT(t2, t1)) {
            tmin = t2;
        }
        else if(TEQ(t1, t2) && (TLT(t1, tmin))) {
            tmin = t1;
        }
    }
    TulisTIME(tmin);
    printf("\n");
    TulisTIME(tmax);
    printf("\n");

    return 0;
}
