#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    scanf("%d", &n);
    int *stack = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &stack[i]);
    }
    scanf("%d", &m);

    int top = n - 1;
    for (i = 0; i < m && top >= 0; i++) {
        top--;
    }

    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    free(stack);
    return 0;
}
