#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure for operators
struct Stack {
    int top;
    char arr[MAX];
};

// Function to initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = c;
    }
}

// Function to pop an element from the stack
char pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1;
}

// Function to get the precedence of an operator
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char *exp, char *postfix) {
    struct Stack s;
    initStack(&s);
    int j = 0;
    
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isalnum(c)) {  // If it's an operand (letters or digits)
            postfix[j++] = c;
        } 
        else if (c == '(') {  // If it's a left parenthesis
            push(&s, c);
        } 
        else if (c == ')') {  // If it's a right parenthesis
            while (!isEmpty(&s) && s.arr[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // Pop '('
        } 
        else {  // If it's an operator
            while (!isEmpty(&s) && precedence(s.arr[s.top]) >= precedence(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }
    
    // Pop remaining operators from the stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    
    postfix[j] = '\0';  // Null terminate the postfix expression
}

int main() {
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[MAX];
    
    infixToPostfix(infix, postfix);
    
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    
    return 0;
}
