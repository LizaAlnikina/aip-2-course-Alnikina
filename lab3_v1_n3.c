#include <stdio.h>
#include <math.h>

int main() {
    double x;
    double epsilon = 1e-5;
    double sum = 0;
    double term;
    int n = 1;
    int sign = 1;

    printf("введите x (-1 ≤ x ≤ 1): ");
    scanf("%lf", &x);
    
    if(x < -1 || x > 1) {
        printf("ошибка: x должен быть в диапазоне [-1, 1]!\n");
        return 1;
    }

    term = -x / 2.0;
    sum = term;
    
    printf("n = 1: член = %.8f, сумма = %.8f\n", term, sum);
    
    n = 2;

    do {
        term = term * (-x) / (n * (n + 1));
        sum += term;
        
        printf("n = %d: член = %.8f, сумма = %.8f\n", n, term, sum);
        
        n++;
    } while(fabs(term) > epsilon);

    printf("\nРезультат:\n");
    printf("Сумма ряда: %.8f\n", sum);
    printf("Количество членов: %d\n", n - 1);
    printf("Точность: %.8f\n", epsilon);
    
    return 0;
}