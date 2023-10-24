#include <stdio.h>

int main() {
    int m, n;
    int banyak = 0;
    scanf("%d", &m);
    scanf("%d", &n);
    int i;
    for(i = m; i <= n; i++) {
        if ((i % 11 == 0) || (i % 111 == 0) || (i % 1111 == 0) || (i % 11111 == 0)) {
            banyak += 1;
        }
    }
    printf("%d\n", banyak);
    return 0;
}
