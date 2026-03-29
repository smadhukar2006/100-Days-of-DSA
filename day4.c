#include <stdio.h>

int removeElement(int nums[], int n, int val) {
    int k = 0; 
    
    for (int i = 0; i < n; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];  
            k++;
        }
    }
    return k;
}

int main() {
    int nums[] = {3, 2, 2, 3, 4, 5};  
    int n = sizeof(nums) / sizeof(nums[0]);
    int val = 3;  
    
    int k = removeElement(nums, n, val);
    
    printf("Number of elements not equal to %d: %d\n", val, k);
    printf("Modified array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}
