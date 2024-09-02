#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue *q, int element) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Insertion successful\n");
    display(q); // Display the queue after insertion
}
void dequeue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = q->front;
    printf("The element %d is deleted\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    display(q); // Display the queue after deletion
}
void display(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = q->front;
    printf("Queue elements are: \n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main() {
    struct Queue q;
    q.front = q.rear = NULL;
    int choice, element;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &element);
            enqueue(&q, element);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("Displaying queue before exiting...\n");
            display(&q);
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
