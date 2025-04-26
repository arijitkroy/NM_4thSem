#include <stdio.h>
#include <math.h>

float f(float x, float y) {
    return (3 * x + pow(y, 2));
}

float eulersMethod(float x0, float y0, float step, float xn) {
    do {
        y0 += step * f(x0, y0);
        x0 += step;
    } while (x0 < xn);
    return y0;
}

float rkMethod(float x0, float y0, float step, float xn) {
    float k, k1, k2, k3, k4;
    do {
        k1 = step * f(x0, y0);
        k2 = step * f(x0 + step/2, y0 + k1/2);
        k3 = step * f(x0 + step/2, y0 + k2/2);
        k4 = step * f(x0 + step, y0 + k3);
        k = (k1 + k2 + k3 + k4) / 4;
        x0 += step; y0 += k;
    } while (x0 < xn);
    return y0;
}

void main() {
    float x, y, step, xn;
    printf("Enter a, b, step, x: ");
    scanf("%f %f %f %f", &x, &y, &step, &xn);
    printf("Euler's solution: %0.3f\nRK's solution: %0.3f", eulersMethod(x, y, step, xn), rkMethod(x, y, step, xn));
}