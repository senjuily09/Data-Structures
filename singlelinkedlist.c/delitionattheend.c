// Linked list deletion at the end
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
struct Node* deleteatend(struct Node* head,int index) {
    struct Node* p = head;
    struct Node*q= head->next;
    while(q->next !=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
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
    head = deleteatend(head,2);
    printf("updated list after deletion\n");
    printList(head);
    return 0;
}


