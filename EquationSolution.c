#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 20

float f(float x) {
    return pow(x, 3) - 3*x - 5;
}

float f_(float x) {
    return 3 * pow(x, 2) - 3;
}

char getOp(float x) {
    return x < 0 ? '-' : '+';
}

void bisection_method(float a, float b, float e) {
    int i = 0; float c;
    printf("n\ta\tb\tc\tf(a)\tf(b)\tf(c)\n");
    do {
        c = (a + b) / 2;
        printf("%d\t%0.4f\t%0.4f\t%0.4f\t%c\t%c\t%c\n", i++, a, b, c, getOp(f(a)), getOp(f(b)), getOp(f(c)));
        if (f(a) * f(c) < 0) b = c;
        else a = c;
    }
    while (fabs(a - b) > e);
    printf("Result: %0.3f\n", c);
}

void newton_raphson_method(float a, float b, float e) {
    int i = 0; float c;
    printf("n\txn\tf(xn)/f_(xn)\txn+1 = xn + f(xn)/f_(xn)\n");
    c = a - f(a) / f_(a);
    do {
        printf("%d\t%0.4f\t%0.4f\t%0.4f\n", i++, a, f(a)/f_(a), c);
        a = c;
        c = a - f(a) / f_(a);
    } while (fabs(a - c) > e);
    printf("Result: %0.3f\n", c);
}

void regula_falsi_method(float a, float b, float e) {
    int i = 0; float c;
    printf("n\ta\tb\tc\tf(a)\tf(b)\tf(c)\n");
    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        printf("%d\t%0.4f\t%0.4f\t%0.4f\t%c\t%c\t%c\n", i++, a, b, c, getOp(f(a)), getOp(f(b)), getOp(f(c)));
        if (f(a) * f(c) < 0) b = c;
        else a = c;
    }
    while (fabs(a - b) > e);
    printf("Result: %0.3f\n", c);
}

void main() {
    float a, b, e;
    while (1) {
        printf("Enter 2 roots: ");
        scanf("%f %f", &a, &b);
        if (f(a) * f(b) < 0) break;
        printf("Invalid roots!\n");
    }
    printf("Enter error: ");
    scanf("%f", &e);
    bisection_method(a, b, e);
    newton_raphson_method(a, b, e);
    regula_falsi_method(a, b, e);
}
