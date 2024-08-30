// Write a program to create a double linked list and perform the
// following menu-based operations on it:
// i. insert an element at specific position
// ii. delete an element from specific position
// iii. Traverse the list

#include<stdio.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
struct Node* insertPosition(struct Node* head, int p) {
    if(head == NULL) {
        if(p==1) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            printf("Enter the data you want to insert: ");
            scanf("%d", &newNode->data);
            newNode->next = NULL;
            newNode->prev = NULL;
            printf("Insertion successful.\n");
            traversal(newNode);
            return newNode;
        }
        printf("Empty List! Can't add element at %d position.\n",p);
        return head;
    }
    if(p==1) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data you want to insert: ");
        scanf("%d", &newNode->data);
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        printf("Insertion successful.\n");
        traversal(newNode);
        return newNode;
    }
    struct Node* ptr = head;
    int c=0;
    while(ptr!=NULL) {
        c++;
        if(c==p-1) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            printf("Enter the data you want to insert: ");
            scanf("%d", &newNode->data);
            newNode->next = ptr->next;
            newNode->prev = ptr;
            ptr->next->prev = newNode;
            ptr->next = newNode;
            break;
        }
        ptr = ptr->next;
    }
    if(c!=p-1){
        printf("Not possible to insert at %d position.",p);
        return head;
    }
    printf("Insertion successful.\n");
    traversal(head);
    return head;
}
struct Node* deletePosition(struct Node* head, int p) {
    if(head==NULL){
        printf("There is no element at %d position.\n");
        return NULL;
    }
    int c = 0;
    struct Node* temp = head;
    struct Node* ptr = NULL;
    while(temp!=NULL) {
        c++;
        if(c==p-1){
            temp->next = temp->next->next;
            ptr->next = NULL;
            free(ptr);
            break;
        }
        ptr = ptr->next;
    }
    if(c!=p-1){
        printf("Not possible to delete at %d position.",p);
        return head;
    }
    printf("Deletion successful.\n");
    traversal(head);
    return head;
}
int main() {
    struct Node* head = (struct node*)malloc(sizeof(struct Node));
    printf("Enter number of elements: ");
    int n,p,c;
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
    printf("Press 1 to Insert a node at specific position.\n");
    printf("Press 2 to Deletion of an element from specific position.\n");
    printf("Press 3 to Traverse the linked list.\n");
    printf("Enter your choice: ");
    int ch;
    scanf("%d",&ch);
    switch (ch){
        case 1:
            printf("Enter the position you want to insert at:");
            scanf("%d",&p);
            head = insertPosition(head,p);
            break;
        case 2:
            printf("Enter the position you want to delete at:");
            scanf("%d",&p);
            head = deletePosition(head,p);
            break;
        case 3:
            traversal(head);
            break;
        default:
            printf("Invalid Input");
            break;
    }
}