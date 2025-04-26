#include <stdio.h>

void main() {
    int i, n;
    float x, y, a, b, sum_x = 0, sum_x2 = 0, sum_y = 0, sum_xy = 0;
    printf("Number of datas: ");
    scanf("%d", &n);
    printf("Enter x & y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x, &y);
        sum_x += x; sum_y += y;
        sum_x2 += x * x; sum_xy += x * y;
    }
    a = (sum_x2 * sum_y - sum_x * sum_xy) / (n * sum_x2 - sum_x * sum_x);
    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    printf("Equation: y = %0.1f + %0.1fx", a, b);
}