#include <stdio.h>

int main() {
    int arr[5];  
    int *ptr;   

    ptr = arr; 


    for (int i = 0; i < 5; i++) {
        scanf("%d", (ptr+i)); 
    }

    printf("Array elements are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}
