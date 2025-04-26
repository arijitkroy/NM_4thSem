#include <stdio.h>
#include <math.h>

void main() {
    int i, n;
    float x, y, A, b, sum_x = 0, sum_x2 = 0, sum_Y = 0, sum_xY = 0;
    printf("Number of datas: ");
    scanf("%d", &n);
    printf("Enter x & y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x, &y);
        sum_x += x; sum_Y += log(y);
        sum_x2 += x * x; sum_xY += x * log(y);
    }
    A = (sum_x2 * sum_Y - sum_x * sum_xY) / (n * sum_x2 - sum_x * sum_x);
    b = (n * sum_xY - sum_x * sum_Y) / (n * sum_x2 - sum_x * sum_x);
    printf("Equation: y = %0.3f e ^ %0.3fx", exp(A), b);
}