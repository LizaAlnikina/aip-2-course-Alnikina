#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[57];
    int B[7][5];
    
    int i, j;

    printf("A (57)\n");
    for(i = 0; i < 57; i++) {
        A[i] = rand() % 200 - 100;
        printf("%4d ", A[i]);
        if((i+1) % 10 == 0) printf("\n");
    }
    printf("\n\n");
    
    printf("B (7x5)\n");
    for(i = 0; i < 7; i++) {
        for(j = 0; j < 5; j++) {
            B[i][j] = rand() % 200 - 100;
            printf("%4d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int max_A = A[0];
    int max_A_index = 0;
    for(i = 1; i < 57; i++) {
        if(A[i] > max_A) {
            max_A = A[i];
            max_A_index = i;
        }
    }
    printf("Максимум в A: A[%d] = %d\n", max_A_index, max_A);

    int max_B = B[0][0];
    int max_B_row = 0, max_B_col = 0;
    for(i = 0; i < 7; i++) {
        for(j = 0; j < 5; j++) {
            if(B[i][j] > max_B) {
                max_B = B[i][j];
                max_B_row = i;
                max_B_col = j;
            }
        }
    }
    printf("Максимум в B: B[%d][%d] = %d\n\n", max_B_row, max_B_col, max_B);

    A[max_A_index] = max_B;
    B[max_B_row][max_B_col] = max_A;
    
    printf("После обмена максимумами:\n");
    printf("A[%d] теперь = %d\n", max_A_index, A[max_A_index]);
    printf("B[%d][%d] теперь = %d\n", max_B_row, max_B_col, B[max_B_row][max_B_col]);
    
    return 0;
}