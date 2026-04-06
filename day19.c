#include <stdio.h>
#include <stdlib.h>


int absVal(int x) {
    return (x < 0) ? -x : x;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    int minSum = absVal(arr[0] + arr[1]);
    int num1 = arr[0], num2 = arr[1];

   
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (absVal(sum) < minSum) {
                minSum = absVal(sum);
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    printf("Elements: %d and %d\n", num1, num2);
    printf("Closest Sum to Zero = %d\n", num1 + num2);

    return 0;
}
