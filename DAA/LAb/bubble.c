#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int a[],int n){
    int noPass=0;
    int noIteration=0;
    int noExchange=0;
    int flag=0;
    for (int i=0;i<n-1;i++){
        noPass++;
        for(int j=0;j<n-1-i;j++){
            noIteration++;
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag=0;
                noExchange++;
            }
        }
        if(flag){
            break;
        }

    }
    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);

    }
    printf("\n");

    printf("Number of passes: %d\n", noPass);
    printf("Number of iterations: %d\n", noIteration);
    printf("Number of exchanges: %d\n", noExchange);

}


int main() {
    printf("enter the size of array: ");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++){
        printf("enter element %d:",i);
        scanf("%d",&a[i]);
    }

    bubbleSort(a,n);
    return 0;
}
