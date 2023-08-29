#include <stdio.h>
#include "test2.h"

int main() {
    waktu waktusiBoy = {"Boy William", 10, 30};
    printf("%s adalah pemilik jam pertama, dan jamnya menunjukkan pukul %d.%d\n", waktusiBoy.pemilikJam, waktusiBoy.jam, waktusiBoy.menit);
}
