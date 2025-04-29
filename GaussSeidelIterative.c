#include <stdio.h>
#include <math.h>
#define SIZE 20

void gaussSeidel(int n, float a[SIZE][SIZE], float b[SIZE], int maxIter, int tolerance) {
    float x[SIZE], x_new[SIZE], error;
    int i, j, iter = 0;

    for (i = 0; i < n; i++) x[i] = 0;

    do {
        iter++;
        error = 0;
        for (i = 0; i < n; i++) {
            x_new[i] = b[i];
            for (j = 0; j < n; j++) 
                if (j != i)
                    x_new[i] -= a[i][j] * x[j];
            x_new[i] /= a[i][i];
            error += fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }
    } while (error > tolerance && iter < maxIter);

    printf("Solution:\n");
    for (i = 0; i < n; i++) printf("x%d = %0.3f\n", i + 1, x[i]);
}

void main() {
    int i, j, n, max_iterations;
    float a[SIZE][SIZE], b[SIZE], tolerance;
    
    printf("Number of variables: ");
    scanf("%d", &n);
    
    printf("Enter augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            if (j == n) scanf("%f", &b[i]);
            else scanf("%f", &a[i][j]);
        }
    }
    
    printf("Enter tolerance and maximum iterations: ");
    scanf("%f %d", &tolerance, &max_iterations);

    gaussSeidel(n, a, b, max_iterations, tolerance);
}