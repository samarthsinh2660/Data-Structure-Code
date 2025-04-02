#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to perform arithmetic operations
int performOperation(int a, int b, char operator) {
    if (operator == '+') {
        return a + b;
    } else if (operator == '-') {
        return a - b;
    } else if (operator == '*') {
        return a * b;
    } else if (operator == '/') {
        return a / b;
    }
    return 0;  // In case of invalid operator
}

// Function to evaluate the postfix expression
int evaluatePostfix(char *exp) {
    int stack[100];  // Stack to store intermediate results
    int top = -1;    // Stack pointer

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // If the character is a number, push it to the stack
        if (isdigit(c)) {
            stack[++top] = c - '0';  // Convert char to integer
        }
        // If the character is an operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = stack[top--];  // Pop the top operand
            int a = stack[top--];  // Pop the next operand

            // Perform the operation and push the result back to the stack
            int result = performOperation(a, b, c);
            stack[++top] = result;
        }
    }

    // The last element in the stack is the result
    return stack[top];
}

int main() {
    // Test case 1
    char exp1[] = "231*+9-";
    int result1 = evaluatePostfix(exp1);
    printf("Result of postfix expression 231*+9-: %d\n", result1);

    // Test case 2
    char exp2[] = "22+2/5*7+";
    int result2 = evaluatePostfix(exp2);
    printf("Result of postfix expression 22+2/5*7+: %d\n", result2);

    return 0;
}
