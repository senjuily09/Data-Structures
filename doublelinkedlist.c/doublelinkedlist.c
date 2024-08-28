#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Linked list insertion at front
struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;

    if (head != NULL) {
        head->prev = ptr;
    }

    return ptr;
}

// Linked list insertion at a specific point
struct Node* insertAtSpecific(struct Node* head, int data, int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    
    if (index == 0) {
        return insertAtFront(head, data);
    }

    while (i != index - 1 && p != NULL) {
        p = p->next;
        i++;
    }  

    if (i != index - 1) {
        printf("Index out of bounds\n");
        return head;
    }

    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;

    if (p->next != NULL) {
        p->next->prev = ptr;
    }

    p->next = ptr;
    return head;
}

// Linked list insertion at end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL) {
        ptr->prev = NULL;
        return ptr;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = ptr;
    ptr->prev = temp;
    return head;
}

// Linked list deletion at the start
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    return head;
}

// Linked list deletion at a specific point
struct Node* deleteAtIndex(struct Node* head, int index) {
    if (head == NULL) return NULL;

    if (index == 0) return deleteFirst(head);

    struct Node* p = head;
    
    for (int i = 0; i < index && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Index out of bounds\n");
        return head;
    }

    if (p->prev != NULL) {
        p->prev->next = p->next;
    }

    if (p->next != NULL) {
        p->next->prev = p->prev;
    }

    free(p);
    return head;
}

// Linked list deletion at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* p = head;

    while (p->next != NULL) {
        p = p->next;
    }

    if (p->prev != NULL) {
        p->prev->next = NULL;
    } else {
        head = NULL;
    }

    free(p);
    return head;
}

// Display the doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
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
