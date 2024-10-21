#include <stdio.h>
#include <string.h>
#define MAX 100

// Stack structure
struct Stack {
    int top;
    char items[MAX];
};

// Function to create a stack
void createStack(struct Stack* s) {
    s->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack* s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        s->items[++s->top] = c;
    }
}

// Function to pop an element from the stack
char pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return s->items[s->top--];
    }
}

// Function to reverse a string using a stack
void reverseString(char str[]) {
    int n = strlen(str);
    struct Stack stack;
    
    createStack(&stack);
    
    // Push all characters onto the stack
    for (int i = 0; i < n; i++) {
        push(&stack, str[i]);
    }
    
    // Pop all characters to reverse the string
    for (int i = 0; i < n; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    gets(str);  // Read string from user
    
    reverseString(str);
    
    printf("Reversed String: %s\n", str);
    
    return 0;
}
