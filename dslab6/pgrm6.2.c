// Write a program to create a circular linked list and display the
// elements of the list.

#include<stdio.h>
struct Node {
    int data;
    struct Node* next;
};
void traversal(struct Node* head) {
    if(head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct Node* ptr = head;
    do {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } while(ptr!=head);
}
int main() {
    struct Node* head = (struct node*)malloc(sizeof(struct Node));
    printf("Enter number of elements\n");
    int n,p;
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    if(n == 0) {
        printf("Please add at least one element: ");
    }
    scanf("%d",&head->data);
    head->next = NULL;
    struct Node* ptr = head;
    for(int i=1; i<n; i++) {
        struct Node* temp = (struct node*)malloc(sizeof(struct Node));
        scanf("%d",&temp->data);
        ptr->next = temp;
        ptr = ptr->next;
    }
    ptr->next = head;
    printf("The elements of the list:\n");
    traversal(head);
}