#include "../boolean.h"
#include "time.h"
#include <stdio.h>

int absolute(int a) {
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}

void CreateTime(time *t, int h, int m, int s) {
    (*t).hours = h;
    (*t).minutes = m;
    (*t).seconds = s; // Menggunakan pointer karena memodifikasi nilai dari variabel yang sudah ada, kalau misalkan tidak memakai pointer berarti malah membuat variabel baru copy dari sebelumnya
}

boolean isTimeValid(int h, int m, int s) {
    if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
        return true;
    } else {
        return false;
    }
}

void readTime(time *t) {
    int h, m, s;
    /* Jika menggunakan algoritma valid invalid:
    printf("Masukkan jam (format 24 jam): ");
    scanf("%d", &h);
    printf("Masukkan menit: ");
    scanf("%d", &m);
    printf("Masukkan detik: ");
    scanf("%d", &s);
    if (isTimeValid(h, m, s)) {
        CreateTime(t, h, m, s);
    } else {
        printf("Jam tidak valid\n"); */
    // Jika menggunakan algoritma do loop
    do {
        printf("masukkan jam:"); scanf("%d", &h);
        printf("masukkan menit:"); scanf("%d", &m);
        printf("masukkan detik:"); scanf("%d", &s);
    }
    while((!isTimeValid(h, m, s))); // Melakukan do dulu sebelum dicek hasilnya agar bisa input, jika salah maka akan di-loop si do nya
    CreateTime(t, h, m, s);
}

void displayTime(time *t) {
    printf("%d:%d:%d\n", (*t).hours, (*t).minutes, (*t).seconds);
}

int timeToSeconds(time t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

time secondsToTime(int s) {
    time t;
    t.hours = s / 3600;
    t.minutes = (s % 3600) / 60;
    t.seconds = (s % 3600) % 60;
    return t;
}

int timeDifference(int a, int b) {
    return absolute(a - b);
}
