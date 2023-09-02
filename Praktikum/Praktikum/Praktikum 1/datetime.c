#include <stdio.h>
#include "datetime.h"
#include <math.h>
#include "boolean.h"
#include "time.h"

int GetMaxDay(int M, int Y) {
    boolean kabisat;
    if ((Y % 400 == 0)) {
        kabisat = true;
    }
    else {
        if (Y % 100 == 0) {
            kabisat = false;
        } else if (Y % 4 == 0) {
            kabisat = true;
        } else {
            kabisat = false;
        }
    }

    if (M == 2) {
        if (kabisat) {
            return 29;
        } else {
            return 28;
        }
    } else if ((M % 2 == 1) && (M <= 7)) {
        return 31;
    } else if ((M % 2 == 0) && (M <= 7)) {
        return 30;
    } else if ((M % 2 == 1) && (M > 7)) {
        return 30;
    } else if ((M % 2 == 0) && (M > 7)) {
        return 31;
    }
    else {
        return 30;
    }
}
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s) {
    if (IsTIMEValid(h, m, s)) {
        if (M > 0 && m <= 12) {
            if (D <= GetMaxDay(M, Y) && D > 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss) {
    if (IsDATETIMEValid(DD, MM, YYYY, hh, mm, ss)) {
        TIME T;
        (*D).DD = DD;
        (*D).MM = MM;
        (*D).YYYY = YYYY;
        CreateTime(&T, hh, mm, ss);
        (*D).T = T;
    }
}
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D) {
    int year, month, day, hour, minute, second;
    scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second);
    while (!IsDATETIMEValid(day, month, year, hour, minute, second)) {
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second);
    }
    CreateDATETIME(D, day, month, year, hour, minute, second);
}
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */

void TulisDATETIME(DATETIME D) {
    printf("%d/%d/%d %d:%d:%d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2) {
    return (Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && TEQ(Time(D1), Time(D2)));
}
/* Mengirimkan true jika D1=D2, false jika tidak */
boolean DNEQ(DATETIME D1, DATETIME D2) {
    return (!DEQ(D1, D2));
}
/* Mengirimkan true jika D1 tidak sama dengan D2 */
boolean DLT(DATETIME D1, DATETIME D2) {
    if (Year(D1) < Year(D2)) {
        return true;
    }
    else if (Year(D1) == Year(D2)) {
        if (Month(D1) < Month(D2)) {
            return true;
        }
        else if (Month(D1) == Month(D2)) {
            if (Day(D1) < Day(D2)) {
                return true;
            }
            else if (Day(D1) == Day(D2)) {
                if (TLT(Time(D1), Time(D2))) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
/* Mengirimkan true jika D1<D2, false jika tidak */
boolean DGT(DATETIME D1, DATETIME D2) {
    if (Year(D1) > Year(D2)) {
        return true;
    }
    else if (Year(D1) == Year(D2)) {
        if (Month(D1) > Month(D2)) {
            return true;
        }
        else if (Month(D1) == Month(D2)) {
            if (Day(D1) > Day(D2)) {
                return true;
            }
            else if (Day(D1) == Day(D2)) {
                if (TGT(Time(D1), Time(D2))) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
/* Mengirimkan true jika D1>D2, false jika tidak */
DATETIME DATETIMENextNDetik(DATETIME D, int N) {
    DATETIME D1;
    Second(Time(D)) += N;

    while (Second(Time(D)) > 59) {
        Second(Time(D)) -= 60;
        Minute(Time(D))++;
    }

    while (Minute(Time(D)) > 59) {
        Minute(Time(D)) -= 60;
        Hour(Time(D))++;
    }

    while (Hour(Time(D)) > 23) {
        Hour(Time(D)) -= 24;
        Day(D)++;
    }

    while (Day(D) > GetMaxDay(Month(D), Year(D))) {
        Day(D) -= GetMaxDay(Month(D), Year(D));
        Month(D)++;
    }

    while (Month(D) > 12) {
        Month(D) -= 12;
        Year(D)++;
    }

    CreateDATETIME(&D1, Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
    return D1;
}
/* Mengirim salinan D dengan detik ditambah N */
DATETIME DATETIMEPrevNDetik(DATETIME D, int N) {
    DATETIME D1;
    Second(Time(D)) -= N;

    while (Second(Time(D)) < 0) {
        Second(Time(D)) += 60;
        Minute(Time(D))--;
    }

    while (Minute(Time(D)) < 0) {
        Minute(Time(D)) += 60;
        Hour(Time(D))--;
    }

    while (Hour(Time(D)) < 0) {
        Hour(Time(D)) += 24;
        Day(D)--;
    }

    while (Day(D) < 1) {
        Month(D)--;
        Day(D) += GetMaxDay(Month(D), Year(D));
    }

    while (Month(D) < 1) {
        Month(D) += 12;
        Year(D)--;
    }

    CreateDATETIME(&D1, Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
    return D1;
}
/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh) {
    long int detik1, detik2, day1;
    day1 = 0;
    int i;
    for (i = Month(DAw); i < Month(DAkh); i++) {
        day1 += GetMaxDay(i, Year(DAw));
    }
    detik1 = TIMEToDetik(Time(DAw)) + 86400 * (Day(DAw) - 1) + 2592000 * (Month(DAw) - 1) + 31536000 * (Year(DAw) - 1);
    detik2 = TIMEToDetik(Time(DAkh)) + 86400 * (Day(DAkh) - 1) + 2592000 * (Month(DAkh) - 1) + 31536000 * (Year(DAkh) - 1);
    return (detik2 - detik1);
}
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */
