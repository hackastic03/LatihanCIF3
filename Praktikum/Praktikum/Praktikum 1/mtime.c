#include <stdio.h>
#include "time.c"
#include <math.h>

void tuliswaktu(TIME t) {
    printf("%d:%d:%d\n", Hour(t), Minute(t), Second(t));
}

int main() {
    int n, i, selisih1, selisih2;
    TIME tmax, tmin, t1, t2, t3, t4;
    scanf("%d", &n);
    printf("[%d]\n", 1);
    BacaTIME(&t3);
    BacaTIME(&t4);
    if (TIMEToDetik(t3) > TIMEToDetik(t4)) {
        tmax = t3;
        tmin = t4;
        selisih2 = TIMEToDetik(t3) - TIMEToDetik(t4);
    }
    else {
        tmax = t4;
        tmin = t3;
        selisih2 = TIMEToDetik(t4) - TIMEToDetik(t3);
    }
    printf("%d\n", selisih2);

    for(i = 2; i <= n; i++) {
        printf("[%d]\n", i);
        BacaTIME(&t1);
        BacaTIME(&t2);
        if (TIMEToDetik(t1) > TIMEToDetik(t2)) {
            selisih1 = TIMEToDetik(t1) - TIMEToDetik(t2);
        }
        else {
            selisih1 = TIMEToDetik(t2) - TIMEToDetik(t1);
        }
        printf("%d\n", selisih1);
        if ((TIMEToDetik(t1) > TIMEToDetik(tmax)) && (TIMEToDetik(t1) > TIMEToDetik(t2))) {
            tmax = t1;
        }
        else if ((TIMEToDetik(t2) > TIMEToDetik(tmax)) && (TIMEToDetik(t2) > TIMEToDetik(t1))) {
            tmax = t2;
        }
        if ((TIMEToDetik(t1) < TIMEToDetik(tmin)) && (TIMEToDetik(t1) < TIMEToDetik(t2))) {
            tmin = t1;
        }
        else if ((TIMEToDetik(t2) < TIMEToDetik(t1)) && (TIMEToDetik(t2) < TIMEToDetik(tmin))) {
            tmin = t2;
        }
    }
    tuliswaktu(tmin);
    tuliswaktu(tmax);

    return 0;
}
