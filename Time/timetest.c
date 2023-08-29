#include <stdio.h>
#include "../boolean.h"
#include "time.c"

int main() {
    time t1, t2;
    readTime(&t1);
    printf("Jam yang dimasukkan adalah %d\n", t1.hours);
    readTime(&t2);
    printf("Selisih dari jam 1 dan jam 2 adalah %d detik\n", timeDifference(timeToSeconds(t1), timeToSeconds(t2)));
    time t3 = secondsToTime(timeDifference(timeToSeconds(t1), timeToSeconds(t2)));
    printf("Selisih dari jam 1 dan jam 2 adalah %02d:%d:%02d\n", t3.hours, t3.minutes, t3.seconds);
}