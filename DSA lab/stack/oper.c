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

// print top  value
int top(struct stack * s){
    return s->arr[s->top];
}

int main() {
    struct stack *s;

    // Allocate memory for the struct stack
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 56);
    push(s, 45);
    push(s, 36);
    printf("Values are pushed to stack\n");

    printf("Value %d is popped from the stack\n", pop(s));  
    printf("Value at index %d from the top is %d\n", 2, peek(s, 2));

    for (int j = 1; j <= s->top + 1; j++) {
        printf("Value at index %d from the top is %d\n", j, peek(s, j));
    }


    return 0;
}
