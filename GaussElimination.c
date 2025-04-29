#include <stdio.h>
#define SIZE 20

void gaussElimination(int n, float mat[SIZE][SIZE]) {
    int i, j, k; float ratio, x[n];
    for (i = 0; i < n; i++) {
        if (mat[i][i] == 0) {
            printf("Mathematical error: Divide by 0\n");
            return;
        }
        for (j = i + 1; j < n; j++) {
            ratio = mat[j][i] / mat[i][i];
            for (k = 0; k <= n; k++) 
                mat[j][k] -= ratio * mat[i][k]; 
        }
    }
    
    for (i = n - 1; i >= 0; i--) {
        x[i] = mat[i][n];
        for (j = i + 1; j < n; j++)
            x[i] -= mat[i][j] * x[j];
        x[i] /= mat[i][i];
    }

    printf("Solution:\n");
    for (i = 0; i < n; i++) 
        printf("x%d = %0.3f\n", i + 1, x[i]);
}

void main() {
    int i, j, n;
    float augMatrix[SIZE][SIZE];

    printf("Number of variables: ");
    scanf("%d", &n);

    printf("Enter augmented matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            scanf("%f", &augMatrix[i][j]);
    
    gaussElimination(n, augMatrix);
}