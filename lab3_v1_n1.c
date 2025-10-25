#include <stdio.h>
#include <math.h>

int main() {
    int n, k;
    double current_value, min_value;

    printf("введите n: ");
    scanf("%d", &n);
    min_value = 1e9;
    
    for(k = 1; k <= n; k++) {
        current_value = pow(k, 3) * sin(n + (double)k/n);

        printf("k = %d: текущее значение = %.4f\n", k, current_value);
        if(current_value < min_value) {
            min_value = current_value;
        }
    }
    
    printf("\nнаименьшее значение: %.4f\n", min_value);
    
    return 0;
}