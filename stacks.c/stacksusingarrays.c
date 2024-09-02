#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100  // Maximum size of the stack
typedef struct Stack {
    int items[MAX];
    int top;
} Stack;
// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}
// Function to check if the stack is full
bool isFull(Stack *s) {
    return s->top == MAX - 1;
}
// Function to check if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}
// Function to add an element to the stack
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is full! Cannot push %d\n", item);
        return;
    }
    s->items[++(s->top)] = item;
    printf("%d pushed to stack\n", item);
}
// Function to remove an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop\n");
        return -1;  // Return -1 or handle underflow appropriately
    }
    return s->items[(s->top)--];
}
// Function to display all elements in the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Nothing to display.\n");
        return;
    }
    printf("Stack elements: \n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d \n", s->items[i]);
    }
    printf("\n");
}
// Main function to interact with the stack
int main() {
    Stack s;
    initStack(&s);
    int choice, value;
    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display(&s);
                break;
            case 4:
                display(&s);
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        // Display the stack after each operation (except exit)
        if (choice != 4) {
            display(&s);
        }
    }
    return 0;
}
