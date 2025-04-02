#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s){
    if(s->top == -1 ){
        return 1;
    }
    else{
        return 0;
    }
}
int full(struct stack *s){
    if(s->top == s->size -1 ){
        return 1;
    }
}


int main(){
    struct stack *s;

    // Allocate memory for the struct stack
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    if(isEmpty(s)){
        printf("Stack is empty");
    }

    return 0;
}
