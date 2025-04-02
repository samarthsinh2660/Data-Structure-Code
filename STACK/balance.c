#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct stack *s) {
    if (s->top == s->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct stack *s, int val) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        int val = s->arr[s->top];
        s->top = s->top - 1;
        return val;
    }
}

int peek(struct stack *s, int i) {
    if (s->top - i + 1 < 0) {
        printf("It is invalid\n");
        return -1;
    } else {
        return s->arr[s->top - i + 1];
    }
}

int match( char *exp){
        struct stack *s;

    // Allocate memory for the struct stack
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    for(int i = 0 ;exp[i] != '\0'; i++){
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
          push(s,exp[i]);
        }
        else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){
            if(isEmpty(s)){
                return 0;
            }
            else {
                pop(s);
            }
        }
    }
    if(isEmpty(s))
    {
        return 1;
    }
    else {
        return 0;
    }
    
}

// print top  value
int top(struct stack * s){
    return s->arr[s->top];
}

int main() {

    char * exp = "[( ])";
int d = match(exp);
 if(d  == 1){
    printf("is balance");
 }
 else{
    printf("IS not balance");
 }
    return 0;
}
