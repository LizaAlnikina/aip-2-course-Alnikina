#include <stdio.h>

int main() {
    double x, y, result;

    printf("введите координаты точки (x y): ");
    scanf("%lf %lf", &x, &y);
    
     if (x == 0 && y == 0) {
        printf("точка лежит в начале координат (0,0)\n");
    }
    else if (x == 0) {
        printf("точка лежит на оси Y\n");
    }
    else if (y == 0) {
        printf("точка на оси X\n");
    }
    // Определяем четверти
    else if (x > 0 && y > 0) {
        printf("точка лежит в I четверти\n");
    }
    else if (x < 0 && y > 0) {
        printf("точка лежит во II четверти\n");
    }
    else if (x < 0 && y < 0) {
        printf("точка лежит в III четверти\n");
    }
    else if (x > 0 && y < 0) {
        printf("точка лежит в IV четверти\n");
    }
    
    return 0;
}