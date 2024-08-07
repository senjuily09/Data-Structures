#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the front of a circular linked list
struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    // If the list is empty, set the next pointer of the new node to itself
    if (head == NULL) {
        ptr->next = ptr;
        return ptr;
    }

    // Find the last node in the list
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    // Set the next pointer of the new node to the current head
    ptr->next = head;

    // Set the next pointer of the last node to the new node
    last->next = ptr;

    return ptr;
}

// Function to print a circular linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (true) {
        printf("%d ", temp->data);
        temp = temp->next;
        if (temp == head) {
            break;
        }
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    head = insertAtFront(head, 8);
    head = insertAtFront(head, 11);
    head = insertAtFront(head, 15);
    head = insertAtFront(head, 24);

    printf("Original list is:\n");
    printList(head);

    head = insertAtFront(head, 56);

    printf("Updated list after insertion:\n");
    printList(head);

    return 0;
}