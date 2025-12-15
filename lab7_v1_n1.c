#include <stdio.h>
#include <stdlib.h>

void fill_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 200 - 100;
    }
}

void fill_matrix(int rows, int cols, int matrix[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 200 - 100;
        }
    }
}

int find_array_max(int arr[], int size, int *index) {
    int max = arr[0];
    *index = 0;
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
            *index = i;
        }
    }
    return max;
}

int find_matrix_max(int rows, int cols, int matrix[rows][cols], 
                    int *row, int *col) {
    int max = matrix[0][0];
    *row = 0;
    *col = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] > max) {
                max = matrix[i][j];
                *row = i;
                *col = j;
            }
        }
    }
    return max;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[57];
    int B[7][5];
    
    fill_array(A, 57);
    fill_matrix(7, 5, B);
    
    int a_idx, b_row, b_col;
    int max_a = find_array_max(A, 57, &a_idx);
    int max_b = find_matrix_max(7, 5, B, &b_row, &b_col);
    
    swap(&A[a_idx], &B[b_row][b_col]);
    
    printf("максимум в A был: %d\n", max_a);
    printf("максимум в B был: %d\n", max_b);
    printf("после обмена: A[%d]=%d, B[%d][%d]=%d\n", 
           a_idx, A[a_idx], b_row, b_col, B[b_row][b_col]);
    
    return 0;
}
