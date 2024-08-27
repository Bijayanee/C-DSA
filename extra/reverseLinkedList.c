// Reversing a linked list
#include<stdio.h>
struct Node
{
    int data;
    struct Node* next;
};
void traversal(struct Node* head) {
    if(head == NULL) {
        printf("Empty List\n");
        return;
    }
    struct Node* ptr = head;
    while (ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
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
    head = reverse(head);
    return 1;
}
