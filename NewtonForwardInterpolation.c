#include <stdio.h>
#define SIZE 20

long long fact(int x) {
    long long f = 1;
    while (x != 0) f *= x--;
    return f;
}

float forward_interpolation(float x[], float y[], int n, float v) {
    float table[SIZE][SIZE], result, u, h, u_term = 1;
    int i, j;
    for (i = 0; i < n; i++) table[i][0] = y[i];
    for (j = 1; j < n; j++)
        for (i = 0; i < n - j; i++) 
            table[i][j] = table[i+1][j-1] - table[i][j-1];
    for (i = 0; i < n; i++) {
        printf("%.4f", table[i][0]);
        for (j = 1; j < n - i; j++)
            printf("\t%.4f", table[i][j]);
        printf("\n");
    }
    h = x[1] - x[0];
    u = (v - x[0]) / h;
    result = table[0][0];
    for (i = 1; i < n; i++) {
        u_term *= (u + i - 1);
        result += u_term * table[0][i] / fact(i);
    }
    return result;
}

void main() {
    float x[SIZE], sinx[SIZE], value;
    int i, n;
    printf("Number of data: ");
    scanf("%d", &n);
    printf("Enter x and sinx:\n");
    for (i = 0; i < n; i++) scanf("%f %f", &x[i], &sinx[i]);
    printf("Value to find: ");
    scanf("%f", &value);
    printf("Result: %0.3f\n", forward_interpolation(x, sinx, n, value));
}
