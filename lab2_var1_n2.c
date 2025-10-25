#include <stdio.h>

int main() {
    double x, y, result;
    printf("введите x и y: ");
    scanf("%lf %lf", &x, &y);
    
    result = (x > 0) ? (x + y) : ((x <= 0 && y < 0) ? (x * y) : (5 * x));
    
    printf("результат: %.2f\n", result);
    
    return 0;
}