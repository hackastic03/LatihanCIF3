#include <stdio.h>
#include "point.h"
//#include "point.c"
#include <math.h>


int main() {
    POINT P1, P2, P3;
    int a, b, c;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    BacaPOINT(&P3);
//    double arrx[] = {Absis(P1), Absis(P2), Absis(P3)};
//    double arry[] = {Ordinat(P1), Ordinat(P2), Ordinat(P3)};
//    // Metode regresi kuadratik
//    double xbar, xbar2, ybar;
//    xbar = (Absis(P1) + Absis(P2) + Absis(P3)) / 3;
//    xbar2 = (pow(Absis(P1), 2) + pow(Absis(P2), 2) + pow(Absis(P3), 2)) / 3;
//    ybar = (Ordinat(P1) + Ordinat(P2) + Ordinat(P3)) / 3;
//    double sumxx, sumxy, sumxx2, sumx2x2, sumx2y;
//    sumxx = 0; sumxy = 0; sumxx2 = 0; sumx2x2 = 0; sumx2y = 0;
//    int i;
//    for (i = 0; i < 3; i++) {
//        sumxx += pow(arrx[i] - xbar, 2);
//        sumxy += ((arrx[i] - xbar) * (arry[i] - ybar));
//        sumxx2 += ((arrx[i] - xbar) * (pow(arrx[i], 2) - pow(xbar, 2)));
//        sumx2x2 += pow((pow(arrx[i], 2) - pow(xbar, 2)), 2);
//        sumx2y += (pow(arrx[i], 2) - pow(xbar, 2)) * (arry[i] - ybar);
//    }
//
//    b = (sumxy * sumx2x2 - sumx2y * sumxx2) / (sumxx * sumx2x2 - pow(sumxx2, 2));
//    c = (sumx2y * sumxx - sumxy * sumxx2) / (sumxx * sumx2x2 - pow(sumxx2, 2));
//    a = ybar - b * xbar - c * pow(xbar, 2);

    int Dx, D;
    int Datas = pow(Absis(P1), 2) * Absis(P2) + pow(Absis(P3), 2) * Absis(P1) + pow(Absis(P2), 2) * Absis(P3);
//    printf("%d\n", Datas);
    int Dbawah = pow(Absis(P3), 2) * Absis(P2) + Absis(P3) * pow(Absis(P1), 2) + pow(Absis(P2), 2) * Absis(P1);
//    printf("%d\n", Dbawah);
    D = Datas - Dbawah;

    int Datas1 = pow(Absis(P1), 2) * Absis(P2) * Ordinat(P3) + pow(Absis(P3), 2) * Absis(P1) * Ordinat(P2) + pow(Absis(P2), 2) * Absis(P3) * Ordinat(P1);
//    printf("%d\n", Datas1);
    int Dbawah1 = pow(Absis(P3), 2) * Absis(P2) * Ordinat(P1) + Absis(P3) * pow(Absis(P1), 2) * Ordinat(P2) + pow(Absis(P2), 2) * Absis(P1) * Ordinat(P3);
//    printf("%d\n", Dbawah1);
    Dx = Datas1 - Dbawah1;
//    printf("%d\n", D);
//    printf("%d\n", Dx);
    a = Dx / D;

    printf("%d\n", a);

//    m1 = (Ordinat(P2) - Ordinat(P1) / (Absis(P2) - Absis(P1)));
//    m2 = (Ordinat(P3) - Ordinat(P2) / (Absis(P3) - Absis(P2)));
//    a = (m2 - m1) / (2 * (Absis(P2) - Absis(P1)));
//    b = (Ordinat(P2) - Ordinat(P1) - (a * (Absis(P2) * Absis(P2) - Absis(P1) * Absis(P1))) / (Absis(P2) - Absis(P1)));
//    c = Ordinat(P2) - (a * Absis(P2) * Absis(P2)) - (b * Absis(P2));
//    printf("%d\n", c);
//    printf("%d\n", b);
//    a = ((P1.Y - P2.Y) * (P2.X - P3.X) - (P2.Y - P3.Y) * (P1.X - P2.X)) / ((P1.X - P2.X) * (P2.X - P3.X) * (P3.X - P1.X));


    return 0;
}
