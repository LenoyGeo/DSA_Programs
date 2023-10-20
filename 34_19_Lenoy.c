/*
Roll No.: 34
Batch: B
Name: Lenoy Geo Thomas
Date: 17.09.2023
Desription: Program to convert Infix to Postfix Expression
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a stack data structure for character elements
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack with a given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop the top element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // Return a special character to indicate an empty stack
}

// Function to return the top element of the stack without popping it
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to determine the precedence of operators
int precedence(char operator) {
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix) {
    int i, k;

    // Create a stack for operators
    struct Stack* stack = createStack(strlen(infix));
    if (!stack) {
        perror("Stack creation failed.");
        exit(EXIT_FAILURE);
    }

    for (i = 0, k = -1; infix[i]; i++) {
        if (isalnum(infix[i])) {
            printf("%c", infix[i]);
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                printf("%c", pop(stack));
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression\n");
                exit(EXIT_FAILURE);
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                printf("%c", pop(stack));
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }
}

int main() {
    char infix[100];
    
    printf("Enter an infix expression: ");
    gets(infix);  // Note: gets is not safe, but for simplicity in this example, we use it.

    printf("Postfix expression: ");
    infixToPostfix(infix);
    printf("\n");

    return 0;
}
