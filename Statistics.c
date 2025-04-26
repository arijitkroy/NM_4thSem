#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 20

double calculateMean(double x[], double y[], int n) {
    int i;
    double sum_xf = 0, sum_f = 0;
    for (i = 0; i < n; i++) {
        sum_xf += x[i] * y[i];
        sum_f += y[i];
    } 
    return (sum_xf / sum_f);
}

double calculateMedian(double lx[], double y[], int n, double h) {
    int i; 
    double cf = 0, sum_f = 0;
    for (i = 0; i < n; i++) sum_f += y[i];
    for (i = 0; i < n; i++) {
        if (cf + y[i] > (sum_f/2)) break;
        cf += y[i];
    }
    return (lx[i] + (((sum_f/2) - cf) / y[i]) * h);
}

double calculateMode(double lx[], double y[], int n, double h) {
    int i, j;
    double f_max = y[0];
    for (i = 1; i < n; i++)
        if (f_max < y[i]) f_max = y[i], j = i;
    return (lx[j] + (y[j] - y[j-1]) / (2.0*y[j] - y[j-1] - y[j+1]) * h);
}

double calculateStandardDeviation(double x[], double y[], int n) {
    int i;
    double sum_x2f = 0, sum_f = 0;
    for (i = 0; i < n; i++) {
        sum_f += y[i];
        sum_x2f += pow(x[i], 2) * y[i];
    }
    return sqrt((sum_x2f / sum_f) - pow(calculateMean(x, y, n), 2));
}

void main() {
    int i, n;
    double p, q, f, h, x[SIZE], y[SIZE], lx[SIZE];
    printf("Number of datas: ");
    scanf("%d", &n);
    printf("Enter range & y:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &p, &q, &f);
        lx[i] = p;
        h = abs(p - q);
        x[i] = (p + q) / 2.0;
        y[i] = 1.0 * f;
    }
    printf("Mean: %0.3lf\nMedian: %0.3lf\nMode: %0.3lf\nStandard Deviation: %0.3lf", 
        calculateMean(x, y, n), 
        calculateMedian(lx, y, n, h), 
        calculateMode(lx, y, n, h), 
        calculateStandardDeviation(x, y, n)
    );
}