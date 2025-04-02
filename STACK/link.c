#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

int isEmpty(struct node *top) {
    return top == NULL;
}

int isFull() {
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr == NULL) {
        return 1;
    } else {
        free(ptr);  // Free the allocated memory to prevent memory leak
        return 0;
    }
}

void trav(struct node* top) {
    while (top != NULL) {  // Traverse until top becomes NULL
        printf("%d \n", top->data);
        top = top->next;
    }
    printf("\n");
}

struct node* push(struct node *top, int data) {
    if (isFull()) {
        printf("The stack is full\n");
        return top;  // Return the current top without modification
    } else {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
}

struct node* pop(struct node **top) {  // Pass a pointer to top to modify it
    if (isEmpty(*top)) {
        printf("Stack is empty\n");
        return NULL;  // Return NULL if the stack is empty
    } else {
        struct node *ptr = *top;
        int x = ptr->data;
        *top = (*top)->next;  // Update the top pointer
        free(ptr);  // Free the memory
        printf("The popped element is %d\n", x);
        return *top;  // Return the new top
    }
}

int peek(struct node * top, int index) {
    struct node * ptr = top;
    int i = 0;

    // Traverse the stack until the desired index is reached
    while (i < index && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }

    // Check if the index is within the range
    if (ptr != NULL) {
        return ptr->data;  // Return the data at the given index
    } else {
        printf("Invalid index\n");
        return -1;  // Return -1 or another indicator if the index is invalid
    }
}

int main() {
    struct node *top = NULL;
    top = push(top, 56);
    top = push(top, 66);
    top = push(top, 78);
    top = pop(&top);  // Pass the address of top
    trav(top);  // Traverse and print the stack

    // Peek at the element at index 1
    int value = peek(top, 1);
    if (value != -1) {
        printf("The peek element at index 1 is %d\n", value);
    }
    
    return 0;
}
