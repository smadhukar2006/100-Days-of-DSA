#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    int total_sum = n * (n + 1) / 2;  
    int arr_sum = 0;

    for (int i = 0; i < n - 1; i++) {
        arr_sum += arr[i];
    }

    return total_sum - arr_sum;  
}

int main() {
    int n = 6;  
    int arr[] = {1, 2, 4, 5, 6};  

    int missing = findMissingNumber(arr, n);
    printf("Missing number: %d\n", missing);

    return 0;
}
