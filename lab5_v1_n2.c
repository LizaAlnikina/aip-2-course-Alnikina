#include <stdio.h>

int main() {
    int A[20];
    int is_increasing = 1;
    int i;
    
    for(i = 0; i < 20; i++) {
        scanf("%d", &A[i]);
    }
    
    for(i = 1; i < 20; i++) {
        if(A[i] <= A[i-1]) {
            is_increasing = 0;
            break;
        }
    }

    if(is_increasing == 1) {
        printf("YES - массив возрастает\n");
    }
    else {
        printf("NO - массив не возрастает\n");
    }
    
    return 0;
}