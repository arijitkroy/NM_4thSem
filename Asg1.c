#include <stdio.h>
#include <math.h>

float f(float x) {
    return (pow(x, 3) - (3 * x) - 5);
}

void main() {
    float a, b, c, e;
    printf("Enter roots: ");
    scanf("%f %f", &a, &b);
    while (f(a) * f(b) >= 0) {
        printf("Invalid roots\nEnter again: ");
        scanf("%f %f", &a, &b);
    }
    printf("Enter error: ");
    scanf("%f", &e);
    printf("a\tb\tc\tf(a)\tf(b)\tf(c)\n");
    do {
        c = (a + b) / 2;
        printf("%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\n", a, b, c, f(a), f(b), f(c));
        if (f(c) * f(a) < 0) b = c;
        else a = c; 
    } while (fabs(b - a) >= e);
    printf("Result: %0.3f", c);
}