#include <stdio.h>
#include <math.h>

float f(float x) {
    return (pow(x, 3) - 3*x - 5);
}

float f_(float x) {
    return (3 * pow(x, 2) - 3);
}

void bisectionMethod(float a, float b, float e) {
    int n = 0; float c;
    printf("Bisection Method:\nn\ta\tb\tc\tf(a)\tf(b)\tf(c)\n");
    do {
        c = (a + b) / 2.0;
        printf("%d\t%0.3f\t%0.3f\t%0.3f\t%c\t%c\t%c\n", n++, a, b, c, f(a) < 0 ? '-' : '+', f(b) < 0 ? '-' : '+', f(b) < 0 ? '-' : '+');
        if (f(c) * f(b) < 0) a = c;
        else b = c;
    } while (fabs(b - a) > e);
    printf("Result: %0.3f\n\n", c);
}

void newtonRaphsonMethod(float a, float e) {
    int n = 0; float c;
    printf("Newton Raphson Method:\nn\txn\tf(xn)\tf_(xn)\tf(xn)/f_(xn)\txn+1 = xn - f(xn)/f_(xn)\n");
    c = a - (f(a) / f_(a));
    do {
        printf("%d\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t\t%0.3f\n", n++, a, f(a), f_(a), f(a)/f_(a), c);
        a = c;
        c = a - (f(a) / f_(a));
    } while (fabs(a - c) > e);
    printf("Result: %0.3f\n\n", a);
}

void regulaFalsiMethod(float a, float b, float e) {
    int n = 0; float c;
    printf("Regula Falsi Method:\nn\ta\tb\tc\tf(a)\tf(b)\tf(c)\n");
    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        printf("%d\t%0.3f\t%0.3f\t%0.3f\t%c\t%c\t%c\n", n++, a, b, c, f(a) < 0 ? '-' : '+', f(b) < 0 ? '-' : '+', f(b) < 0 ? '-' : '+');
        if (f(c) * f(b) < 0) a = c;
        else b = c;
    } while (fabs(b - a) > e);
    printf("Result: %0.3f\n\n", c);
}

void main() {
    float r1, r2, error;
    do {
        printf("Enter two roots: ");
        scanf("%f %f", &r1, &r2);
        if (f(r1) * f(r2) >= 0) printf("Wrong roots!\n");
        else break;
    } while (1);
    printf("Enter error: ");
    scanf("%f", &error);
    bisectionMethod(r1, r2, error);
    newtonRaphsonMethod(r1, error);
    regulaFalsiMethod(r1, r2, error);
}