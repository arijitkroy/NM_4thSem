#include <stdio.h>
#define SIZE 20

void main() {
    int i, j, n;
    float x[SIZE], y[SIZE], v, p, res = 0;
    printf("Number of datas: ");
    scanf("%d", &n);
    printf("Enter x & y:\n");
    for (i = 0; i < n; i++) scanf("%f %f", &x[i], &y[i]);
    printf("Enter value to find: ");
    scanf("%f", &v);
    for (i = 0; i < n; i++) {
        p = 1.0;
        for (j = 0; j < n; j++) if (i != j) p *= (v - x[j]) / (x[i] - x[j]);
        res += p * y[i];
    }
    printf("Interpolated value: %0.3f", res);
}