#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    int k = 0;

    for (int i = 0; i < n; i++) {
        
        if (i == n - 1 || arr[i] != arr[i + 1]) {
            arr[k++] = arr[i];
        }
    }

    
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
