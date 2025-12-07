#include <stdio.h>
#include <math.h>

double f1(double x) {
    return 1.0 / (x * x + 1.0);
}

double f2(double x) {
    return cos(5.0 * x);
}

double trapezoidal(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (func(a) + func(b)) / 2.0;
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += func(x);
    }
    
    return sum * h;
}

int main() {
    int N = 20;

    double integral1 = trapezoidal(f1, -2.0, 2.0, N);

    double integral2 = trapezoidal(f2, -2.0, 3.0, N);
    printf("при N = %d:\n", N);
    printf("∫[-2, 2] dx/(x^2+1) = %.6f\n", integral1);
    printf("∫[-2, 3] cos(5x) dx = %.6f\n", integral2);
    
    return 0;
}