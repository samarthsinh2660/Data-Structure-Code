#include<stdio.h>

int main(){
    int size;
   
    printf("enter the size of an array:- ");
    scanf("%d", &size);

    int arr[size];
    int *ptr;
    ptr = arr;

    for(int i = 0; i< size;i++){
        printf("enter the %d element of array:- ", i);
        scanf("%d", (ptr+i));
    }    
    int max = 0;
    int mini = 0;
    for(int i = 0; i< size;i++){
        if(*(ptr+ max) < *(ptr+i)){
             max = i;
        }
    }
    for(int i = 0; i< size;i++){
        if(*(ptr+ mini) > *(ptr+i)){
             mini = i;
        }
    }
    printf("max value is :- %d\n"  , *(ptr+max));
    printf("mini value is :- %d\n",*(ptr+mini));

}