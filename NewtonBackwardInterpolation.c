#include <stdio.h>
#define SIZE 20

long long fact(int x) {
    long long f = 1;
    while (x != 0) f *= x--;
    return f;
}

void displayTable(float x[SIZE], float table[SIZE][SIZE], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("%0.2f\t", x[i]);
        for (j = 0; j <= i; j++) {
            printf("%0.4f\t", table[j][i]);
        }
        printf("\n");
    }
}

void main() {
    int i, j, n;
    float x[SIZE], table[SIZE][SIZE], h, u, term = 1, res, v;
    printf("Number of datas: ");
    scanf("%d", &n);
    printf("Enter x & y:\n");
    for (i = 0; i < n; i++) scanf("%f %f", &x[i], &table[0][i]);
    for (i = 1; i < n; i++)
        for (j = n - 1; j >= i; j--)
            table[i][j] = table[i-1][j] - table[i-1][j-1];
    printf("Enter value to find: ");
    scanf("%f", &v);
    displayTable(x, table, n);
    h = x[n-1] - x[n-2];
    u = (v - x[n-1]) / h;
    res = table[0][n-1];
    for (i = 1; i < n; i++) {
        term *= (u + (i - 1));
        res += (term * table[i][n-1]) / fact(i);
    }
    printf("Interpolated value: %0.3f", res);
}