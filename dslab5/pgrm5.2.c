// perform following operations using function on the single
// linked list:
// i. search an element in the list
// ii. sort the list in ascending order
// iii. reverse the list

#include<stdio.h>
struct Node {
    int data;
    struct Node* next;
};
void traversal(struct Node* head) {
    if(head == NULL) {
        printf("Empty List!\n");
        return;
    }
    struct Node* ptr = head;
    while (ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int search(struct Node* head, int element) {
    struct Node* ptr = head;
    int c = 0;
    while(ptr!=NULL) {
        c++;
        if(ptr->data == element)
            return c;
        ptr = ptr->next;
    }
    return -1;
}
struct Node* reverse(struct Node* head) {
    if(head == NULL) {
        printf("Empty list!");
        return NULL;
    }
    struct Node* prev = head;
    struct Node* ptr = head->next;
    head->next = NULL;
    while(ptr != NULL) {
        struct Node* temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    head = prev;
    printf("Reversed Linked List: ");
    traversal(head);
    return head;
}
