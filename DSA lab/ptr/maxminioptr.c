#include <stdio.h>


void maxandmini(int *ptr, int size) {
    int max = 0;
    int mini = 0;

    
    for (int i = 0; i < size; i++) {
        if (*(ptr + max) < *(ptr + i)) {
            max = i;
        }
    }

  
    for (int i = 0; i < size; i++) {
        if (*(ptr + mini) > *(ptr + i)) {
            mini = i;
        }
    }

   
    printf("Max value is: %d\n", *(ptr + max));
    printf("Min value is: %d\n", *(ptr + mini));
}

int main() {
    int size;

   
    printf("Enter the size of an array: ");
    scanf("%d", &size);

    int arr[size]; 
    int *ptr = arr;
    for (int i = 0; i < size; i++) {
        printf("Enter the %d element of array: ", i);
        scanf("%d", (ptr + i));
    }
    maxandmini(arr, size);

    return 0;
}
