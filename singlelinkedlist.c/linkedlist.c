#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Linked list insertion at front
struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Linked list insertion at a specific point
struct Node* insertAtSpecific(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while (i != index - 1 && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Index out of bounds\n");
        return head;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Linked list insertion at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;
    }
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

// Linked list deletion at the start
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Linked list deletion at a specific point
struct Node* deleteAtIndex(struct Node* head, int index) {
    if (head == NULL) return NULL;
    if (index == 0) return deleteFirst(head);

    struct Node* p = head;
    struct Node* q = head->next;
    for (int i = 0; i < index - 1 && q != NULL; i++) {
        p = p->next;
        q = q->next;
    }
    if (q == NULL) {
        printf("Index out of bounds\n");
        return head;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Linked list deletion at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Display the list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    int run = 1;
    while (run) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at specific position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtFront(head, data);
                display(head);
                break;
                
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                display(head);
                break;
                
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insertAtSpecific(head, data, position);
                display(head);
                break;
                
            case 4:
                head = deleteFirst(head);
                display(head);
                break;
                
            case 5:
                head = deleteAtEnd(head);
                display(head);
                break;
                
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtIndex(head, position);
                display(head);
                break;
                
            case 7:
                display(head);
                break;
                
            case 8:
                run = 0;
                break;
                
            default:
                printf("Invalid choice\n");
        }
    }
    // Print the final state of the list before exiting
    printf("\nFinal list:\n");
    display(head);
    return 0;
}
