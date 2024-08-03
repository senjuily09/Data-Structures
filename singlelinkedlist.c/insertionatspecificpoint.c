// Linked list insertion at specific point
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void printList(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node* insertAtSpecific(struct Node* head, int data,int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p= head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next= p->next;
    p->next= ptr;
    return head;
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    head->data = 8;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 15;
    third->next = fourth;
    fourth->data = 24;
    fourth->next = NULL;
    printf("original list is\n");
    printList(head);
    head = insertAtSpecific(head, 56,1);
    printf("updated list after insertion\n");
    printList(head);
    return 0;
}
