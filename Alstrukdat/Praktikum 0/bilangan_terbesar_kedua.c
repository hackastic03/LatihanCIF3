#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, big1, big2;
    scanf("%d", &n);
    int arr[n];
    int i = 0;
    for(i; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    i = 0;
    big1 = arr[0];
    big2 = 0;
    for(i; i<n; i++) {
        //printf("%d", arr[i]);
        if (arr[i] > big1) {
            big1 = arr[i];
        }
    }
    i = 0;
    for(i; i < n; i++) {
        if ((arr[i] > big2) && (arr[i] < big1)) {
            big2 = arr[i];
        }
    }
    printf("%d\n", big2);
    return 0;
}
