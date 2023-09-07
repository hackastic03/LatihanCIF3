#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int i;
    for(i = 1; i<=m;i++){
        if(i % n == 0) {
            printf("happy\n");
        }
        else{
            printf("%d\n", i);
        }
    }
    return 0;
}
