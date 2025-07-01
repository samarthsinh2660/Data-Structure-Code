#include <stdio.h>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int noexch , noit,nopass = 0;
    int flag;

    for (int i = 0; i < n - 1; i++) {
        nopass++;
        flag = 1;
        for (int j = 0; j < n - i - 1; j++) {
            noit++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
                noexch++;
            }
        }
        if(flag ==1 ){
            break;
        }
    }

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
