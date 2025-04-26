#include <stdio.h>
#include <math.h>

float f(float x) {
    return (x * sin(x) + pow(x, 3));
}

float trapezoidal(float a, float b, int n) {
    int i;
    float h = (b - a) / (1.0 * n), sum = f(a) + f(b);
    for (i = 1; i < n; i++) sum += 2 * f(a + i * h);
    return sum * (h / 2);
}

float simpson(float a, float b, int n) {
    int i;
    float h = (b - a) / (1.0 * n), sum = f(a) + f(b);
    for (i = 1; i < n; i++) {
        if (i % 2 == 0) sum += 2 * f(a + i * h);
        else sum += 4 * f(a + i * h);
    }
    return sum * (h / 3);
}

void main() {
    float a, b, n;
    printf("Enter a, b, n: ");
    scanf("%f %f %f", &a, &b, &n);
    printf("Result of Trapezoidal method: %0.3f\nResult of Simpson's 1/3rd method: %0.3f", trapezoidal(a, b, n), simpson(a, b, n));
}