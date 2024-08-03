// Linked list insertion at end
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
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node*p=head;
    
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
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
    head = insertAtEnd(head, 56);
    printf("updated list after insertion\n");
    printList(head);
    return 0;
}




