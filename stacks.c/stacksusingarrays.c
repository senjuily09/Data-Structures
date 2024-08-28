#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // define the maximum size of the stack

void push(int stack[], int *top)
{
    int element;
    if (*top == MAX - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d", &element);
        stack[++(*top)] = element;
        printf("Insertion successful\n");
    }
}

void pop(int stack[], int *top)
{
    int element2;
    if (*top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        element2 = stack[(*top)--];
        printf("The element %d is at the position %d is deleted\n", element2, *top + 1);
    }
}

void display(int stack[], int top)
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are: \n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int top = -1;
    int stack[MAX];
    int choice;

    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(stack, &top);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            display(stack, top);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}