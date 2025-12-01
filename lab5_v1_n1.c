#include <stdio.h>

int main() {
    int M[25];

    int unique[25];
    
    int unique_count = 0;
    
    int i, j, is_unique;
    
    printf("Введите 25 элементов массива M:\n");

    for(i = 0; i < 25; i++) {
        scanf("%d", &M[i]);
    }
    
    printf("\nИсходный массив M:\n");
    for(i = 0; i < 25; i++) {
        printf("%d ", M[i]);
    }
    printf("\n\n");

    for(i = 0; i < 25; i++) {

        is_unique = 1;
        
        for(j = 0; j < 25; j++) {

            if(i != j && M[i] == M[j]) {

                is_unique = 0;

                break;
            }
        }
        
        if(is_unique == 1) {
            unique[unique_count] = M[i];
            unique_count++;
        }
    }
    
    printf("Уникальные элементы (встречаются один раз):\n");
    
    if(unique_count == 0) {
        printf("В массиве нет уникальных элементов.\n");
    } 
    else {
        for(i = 0; i < unique_count; i++) {
            printf("%d ", unique[i]);
        }
        printf("\n");
        printf("Всего уникальных элементов: %d\n", unique_count);
    }
    
    return 0;
}