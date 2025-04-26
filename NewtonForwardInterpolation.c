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
        for (j = 0; j < n - i; j++) {
            printf("%0.4f\t", table[j][i]);
        }
        printf("\n");
    }
}

void main() {
    int i, j, n; 
    float x[SIZE], table[SIZE][SIZE], h, u, res, v, term = 1;
    printf("Number of datas: ");
    scanf("%d", &n);
    printf("Enter x & y:\n");
    for (i = 0; i < n; i++) scanf("%f %f", &x[i], &table[0][i]);
    printf("Enter value to find: ");
    scanf("%f", &v);
    for (i = 1; i < n; i++) 
        for (j = 0; j < n - i; j++) 
            table[i][j] = table[i-1][j+1] - table[i-1][j];
    displayTable(x, table, n);
    h = x[1] - x[0];
    u = (v - x[0]) / h;
    res = table[0][0];
    for (i = 1; i < n; i++) {
        term *= (u - (i - 1));
        res += (u * table[i][0]) / fact(i);
    }
    printf("Interpolated Result: %0.3f", res);
}