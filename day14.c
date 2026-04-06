#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int mat[n][n];
    int isIdentity = 1; 

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && mat[i][j] != 1) {
                isIdentity = 0; 
                break;
            }
            if (i != j && mat[i][j] != 0) {
                isIdentity = 0;  
                break;
            }
        }
        if (!isIdentity) break;
    }

    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not Identity Matrix\n");
    }

    return 0;
}
