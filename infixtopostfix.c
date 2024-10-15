#include <stdio.h>
#include <ctype.h>  // For isdigit() and isalpha()
#include <stdlib.h> // For exit() function

#define MAX 100  // Define the maximum size of the stack
char stack[MAX];
int top = -1;
// Function to push an element to the stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
}
// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}
// Function to get the precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        char ch = infix[i];
        
        // If the character is an operand, add it to the postfix expression
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If the character is '(', push it to the stack
        else if (ch == '(') {
            push(ch);
        }
        // If the character is ')', pop and add to postfix until '(' is encountered
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // Remove '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }
    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  // Null terminate the postfix expression
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
