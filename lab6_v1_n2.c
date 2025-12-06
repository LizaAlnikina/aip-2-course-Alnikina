#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int rows = 6, cols = 8;
    int i, j;

    int** X = (int**)malloc(rows * sizeof(int*));
    for(i = 0; i < rows; i++) {
        X[i] = (int*)malloc(cols * sizeof(int));
    }
    int initial_data[6][8] = {
        {5, 12, -3, 8, 0, 7, -1, 15},
        {-2, 9, 4, -6, 11, 3, 10, -8},
        {7, -4, 6, 13, -5, 2, 14, 1},
        {3, -7, 8, -9, 12, -2, 5, 16},
        {-1, 10, -11, 4, 9, -3, 6, 17},
        {2, -12, 13, -10, 8, -4, 7, 18}
    };
    
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            X[i][j] = initial_data[i][j];
        }
    }
    
    printf("Матрица X (%dx%d):\n", rows, cols);
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%4d ", X[i][j]);
        }
        printf("\n");
    }
    
    int Xmin_positive = INT_MAX;
    int Xmax = INT_MIN;
    
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            int current = X[i][j];
            
            if(current > 0 && current < Xmin_positive) {
                Xmin_positive = current;
            }

            if(current > Xmax) {
                Xmax = current;
            }
        }
    }
    

    if(Xmin_positive == INT_MAX) {
        printf("ОШИБКА: В матрице нет положительных элементов!\n");
        printf("Невозможно вычислить Z.\n");
    }
    else {
        printf("Минимальный положительный элемент (Xmin): %d\n", Xmin_positive);
        printf("Максимальный элемент (Xmax): %d\n", Xmax);
        printf("Сумма: Xmax + Xmin = %d + %d = %d\n", 
               Xmax, Xmin_positive, Xmax + Xmin_positive);
        
        float Z = (float)Xmin_positive / (Xmax + Xmin_positive);
        
        printf("\nВычисление Z:\n");
        printf("Z = Xmin / (Xmax + Xmin)\n");
        printf("Z = %d / (%d + %d)\n", Xmin_positive, Xmax, Xmin_positive);
        printf("Z = %d / %d\n", Xmin_positive, Xmax + Xmin_positive);
        printf("Z = %.6f\n", Z);
    }

    
    int positive_count = 0;
    int negative_count = 0;
    int zero_count = 0;
    
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(X[i][j] > 0) positive_count++;
            else if(X[i][j] < 0) negative_count++;
            else zero_count++;
        }
    }
    
    for(i = 0; i < rows; i++) {
        free(X[i]);
    }
    free(X);
    printf("\nПамять освобождена\n");
    
    return 0;
}
