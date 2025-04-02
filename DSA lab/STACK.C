#include <stdio.h>

#define MAX_SIZE 3

typedef struct {
    int s1[MAX_SIZE];
    int top;
} Stack;

Stack stack;

void initStack() {
    stack.top = -1; 
}

int isFull() {
    return stack.top == MAX_SIZE - 1;
}

int isEmpty() {
    return stack.top == -1;
}

int push(int value) {
    if (isFull()) {
        printf("Stack overflow!\n");
        return -1; 
    }
    stack.s1[++stack.top] = value;
    return 0; 
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return -1; 
    }
    return stack.s1[stack.top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1; 
    }
    return stack.s1[stack.top];
}

void printStack() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d ", stack.s1[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    initStack();  // Initialize stack

    do {
        // Display menu
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform operations based on user choice
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                printStack();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);  // Loop until user chooses to exit

    return 0;
}
