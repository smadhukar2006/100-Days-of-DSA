#include <stdio.h>

int main() {
    int n, pos, i;
    
    // Read number of elements
    scanf("%d", &n);
    
    int arr[n];
    
    // Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read position to delete (1-based)
    scanf("%d", &pos);
    
    
    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 0;
    }
    
    
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    
    for (i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i != n - 2) {
            printf(" ");
        }
    }
    
    return 0;
}
