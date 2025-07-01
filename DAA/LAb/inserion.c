#include <stdio.h>

void insertionSort(int arr[], int n) {
    int noComparisons = 0;
    int noShifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Counting comparisons and shifts
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  
            j--;
            noComparisons++;  
        }
        arr[j + 1] = key; 

        
        if (j >= 0) {
            noComparisons++;
        }
    }

    printf("Number of comparisons: %d\n", noComparisons);
    printf("Number of shifts: %d\n", noShifts);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original Array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}
