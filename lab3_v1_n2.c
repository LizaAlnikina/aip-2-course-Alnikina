#include <stdio.h>

int main() {
    int M, N;
    int original_M, original_N;
    int divisor;
    
    printf("введите числитель M: ");
    scanf("%d", &M);
    printf("введите знаменатель N: ");
    scanf("%d", &N);
    
    original_M = M;
    original_N = N;
    
    int a = M, b = N;
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    divisor = a;

    M = original_M / divisor;
    N = original_N / divisor;

    printf("\nисходная дробь: %d/%d\n", original_M, original_N);
    printf("сокращенная дробь: %d/%d\n", M, N);
    printf("НОД: %d\n", divisor);
    
    return 0;
}