#include <stdio.h>
#include "test2.h"
#include "../boolean.h"
// Created by Hackastic on 8/29/2023.
//

int volumeTabung(int r, int t) {
    return PI * r * r * t;
}

boolean checkOrigin(double x, double y) {
    if (x == 0 && y == 0) {
        return true;
    } else {
        return false;
    }
}


