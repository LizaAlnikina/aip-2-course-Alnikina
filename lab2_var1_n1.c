#include <stdio.h>
#include <math.h>

int main() {
    double x, q;
    printf("введите x: ");
    scanf("%lf", &x);
    
    q = tan(x) - log(sin(x)/12) + exp(x*x - 5);
    
    printf("результат: q = %.4f\n", q);
    
    return 0;
}