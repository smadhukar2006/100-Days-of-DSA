#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

   
    k = k % n;

    int rotated[n];
    int index = 0;

   
    for (int i = n - k; i < n; i++) {
        rotated[index++] = arr[i];
    }

    
    for (int i = 0; i < n - k; i++) {
        rotated[index++] = arr[i];
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }
    printf("\n");

    return 0;
}
