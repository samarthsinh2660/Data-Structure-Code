#include<stdio.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}

int main(){
    int x= 5 , y =6;
    printf("The value of element ares  x= %d  y = %d ",x,y);
    swap(&x,&y);
    printf("After swap   x= %d  y=%d" , x,y);

    return 0;
}