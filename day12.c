#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int mat[m][n];

   
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

  
    if (m != n) {
        printf("Not Symmetric\n");
        return 0;
    }

    
    int isSymmetric = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric) {
        printf("Symmetric\n");
    } else {
        printf("Not Symmetric\n");
    }

    return 0;
}
