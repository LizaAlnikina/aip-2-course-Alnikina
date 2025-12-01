#include <stdio.h>

int main() {
    int X[6][8] = {
        {5, 12, -3, 8, 0, 7, -1, 15},
        {-2, 9, 4, -6, 11, 3, 10, -8},
        {7, -4, 6, 13, -5, 2, 14, 1},
        {3, -7, 8, -9, 12, -2, 5, 16},
        {-1, 10, -11, 4, 9, -3, 6, 17},
        {2, -12, 13, -10, 8, -4, 7, 18}
    };
    
    int Xmin = X[0][0];
    int Xmax = X[0][0];
    int i, j;
    
    printf("Матрица X:\n");
    for(i = 0; i < 6; i++) {
        for(j = 0; j < 8; j++) {
            printf("%4d ", X[i][j]);
            
            if(X[i][j] < Xmin) Xmin = X[i][j];
            if(X[i][j] > Xmax) Xmax = X[i][j];
        }
        printf("\n");
    }
    
    float Z = (float)Xmin / (Xmax + Xmin);
    
    printf("\nXmin = %d, Xmax = %d\n", Xmin, Xmax);
    printf("Z = %.4f\n", Z);
    
    return 0;
}