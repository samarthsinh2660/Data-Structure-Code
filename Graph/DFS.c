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

    int visited[7] = {0};
    int i = 0;
    int a[7][7] = {        // Adjacency matrix representation of the graph
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    visited[i] = 1;
    printf("%d ", i); // Start with the initial node
    push(s, i);

    // Process nodes in depth-first order
    while (!isEmpty(s)) {
        int d = pop(s);
        printf("%d ", d);  // Print the current node

        // Check all the neighbors of the current node
        for (int j = 0; j < 7; j++) {
            if (a[d][j] == 1 && visited[j] == 0) {
                visited[j] = 1;  // Mark the neighbor as visited
                push(s, j);      // Push the unvisited neighbor onto the stack
            }
        }
    }

    return 0;
}
