#include <stdio.h>


int digit(int a){
    int sum = 0;
    int rest = 0;
    while(a > 9) {
        sum = sum + (a % 10);
        a = a / 10;
    }
    sum += a;
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", digit(n));
    return 0;
}
