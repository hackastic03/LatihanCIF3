#include <stdio.h>
#include "time.h"
#include "boolean.h"

boolean IsTIMEValid (int H, int M, int S) {
    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}

void CreateTime(TIME *T, int HH, int MM, int SS){
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void BacaTIME (TIME *T) {
    int h, m, s;
    do {
        scanf("%d %d %d", &h, &m, &s);
        if (!(IsTIMEValid(h, m, s))) {
            printf("Jam tidak valid\n");
        }
    } while(!(IsTIMEValid(h, m, s)));
    CreateTime(T, h, m, s);
}

void TulisTIME (TIME T) {
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik (TIME T) {
    return 3600 * Hour(T) + 60 * Minute(T) + Second(T);
}

TIME DetikToTIME (long N) {
    int h, m, s;
    TIME T1;
    N = N % 86400;
    h = N / 3600;
    m = (N % 3600) / 60;
    s = (N % 3600) % 60;
    CreateTime(&T1, h, m, s);
    return T1;
}

boolean TEQ (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) == TIMEToDetik(T2));
}

boolean TNEQ (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) != TIMEToDetik(T2));
}

boolean TLT (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}

boolean TGT (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

TIME NextDetik (TIME T) {
    return (DetikToTIME(TIMEToDetik(T) + 1));
}

TIME NextNDetik (TIME T, int N) {
    return (DetikToTIME(TIMEToDetik(T) + N));
}

TIME PrevDetik (TIME T) {
    return (((TIMEToDetik(T) - 1) < 0) ? (DetikToTIME(86400 + (TIMEToDetik(T) - 1))) : DetikToTIME((TIMEToDetik(T) - 1)));
}

TIME PrevNDetik (TIME T, int N) {
    return (((TIMEToDetik(T) - N) < 0) ? (DetikToTIME(86400 + (TIMEToDetik(T) - N))) : DetikToTIME((TIMEToDetik(T) - N)));
}

long Durasi (TIME TAw, TIME TAkh) {
    long s;
    s = TIMEToDetik(TAkh) - TIMEToDetik(TAw);
    return ((s < 0) ? (86400 + s) : s);
}