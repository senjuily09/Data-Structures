#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 100

int top = -1;
int stack[max];

// Function to push an element onto the stack
void push(int value) {
    if (top == max - 1) {
        printf("Stack is full, can't push further\n");
    } else {
        top = top + 1;
        stack[top] = value;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack is empty, deletion is not possible\n");
        return -1;  // Return a dummy value when stack is empty
    } else {
        int value = stack[top];
        top = top - 1;
        return value;
    }
}

// Function to display the elements in the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is: ");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function to evaluate the postfix expression
int main() {
    char exp[] = "569*+";
    int i, j, k, value;

    // Loop through the expression until the end
    for (i = 0; exp[i] != '\0'; i++) {
        // If the character is a digit, push it onto the stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            // Pop the top two elements for the operation
            k = pop();
            j = pop();

            // Perform the operation based on the operator
            switch (exp[i]) {
                case '+':
                    value = j + k;
                    break;
                case '-':
                    value = j - k;
                    break;
                case '*':
                    value = j * k;
                    break;
                case '/':
                    value = j / k;
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }

            // Push the result back onto the stack
            push(value);
        }
    }

    // The final result will be the last element on the stack
    printf("Evaluation of postfix expression is: %d\n", stack[top]);

    return 0;
}
