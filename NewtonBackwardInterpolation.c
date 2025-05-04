#include <stdio.h>
#define SIZE 20

long long fact(int x) {
    long long f = 1;
    while (x != 0) f *= x--;
    return f;
}

float backward_interpolation(float x[], float y[], int n, float v) {
    float table[SIZE][SIZE], h, u, u_term = 1, result;
    int i, j;
    for (i = 0; i < n; i++) table[i][0] = y[i];
    for (j = 1; j < n; j++)
        for (i = n - 1; i >= j; i--)
            table[i][j] = table[i][j-1] - table[i-1][j-1];
    for (i = 0; i < n; i++) {
        printf("%0.4f", table[i][0]);
        for (j = 1; j <= i; j++)
            printf("\t%0.4f", table[i][j]);
        printf("\n");
    }
    h = x[1] - x[0];
    u = (v - x[n-1]) / h;
    result = table[n-1][0];
    for (i = 1; i < n; i++) {
        u_term *= (u + i - 1);
        result += u_term * table[n-1][i] / fact(i);
    }
    return result;
}

void main() {
    float x[SIZE], y[SIZE], value;
    int i, n;
    printf("Number of data: ");
    scanf("%d", &n);
    printf("Enter x and y:\n");
    for (i = 0; i < n; i++) scanf("%f %f", &x[i], &y[i]);
    printf("Value to find: ");
    scanf("%f", &value);
    printf("Result: %0.3f\n", backward_interpolation(x, y, n, value));
}
