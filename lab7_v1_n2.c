#include <stdio.h>
#include <stdlib.h>
void calculate_sums(void* data, int rows, int cols, int is_array, 
                    float* sum_pos, float* sum_neg) {
    *sum_pos = 0;
    *sum_neg = 0;
    
    if(is_array) {
        int* arr = (int*)data;
        for(int i = 0; i < rows; i++) {
            if(arr[i] > 0) {
                *sum_pos += arr[i];
            }
        }
    } else {
        int (*matrix)[cols] = (int (*)[cols])data;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] < 0) {
                    *sum_neg += matrix[i][j];
                }
            }
        }
    }
}

int main() {
    int A[70];
    int B[7][9];
    
    for(int i = 0; i < 70; i++) {
        A[i] = rand() % 200 - 100;
    }
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 9; j++) {
            B[i][j] = rand() % 200 - 100;
        }
    }

    float S1, S2;

    calculate_sums(A, 70, 0, 1, &S1, &S2);
    
    float temp;
    calculate_sums(B, 7, 9, 0, &temp, &S2);
    
    printf("S1 (сумма положительных в A) = %.2f\n", S1);
    printf("S2 (сумма отрицательных в B) = %.2f\n", S2);

    if(S1 - S2 == 0) {
        printf("Ошибка: S1 - S2 = 0, деление на ноль!\n");
    } else {
        float Z = (S1 + S2) / (S1 - S2);
        printf("Z = (S1 + S2) / (S1 - S2) = (%.2f + %.2f) / (%.2f - %.2f)\n", 
               S1, S2, S1, S2);
        printf("Z = %.6f\n", Z);
    }
    
    return 0;
}