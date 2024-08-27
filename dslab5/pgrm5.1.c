// Write a program to create a single linked list of n nodes and perform
// the following menu-based operations on it using function:
// i. Insert a node at specific position
// ii. Deletion of an element from specific position
// iii. Count nodes
// iv. Traverse the linked list

#include<stdio.h>
struct Node {
    int data;
    struct Node* next;
};
void traversal(struct Node* head) {
    if(head == NULL) {
        printf("Empty List.\n");
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
        newNode->next = head;
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
    struct Node* ptr = head;
    while(ptr->next!=NULL) {
        c++;
        if(c==p-1){
            struct Node* temp = ptr->next;
            ptr->next = ptr->next->next;
            temp->next = NULL;
            free(temp);
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
int countNodes(struct Node* head) {
    struct Node* ptr = head;
    int c = 0;
    while(ptr!=NULL) {
        c++;
        ptr = ptr->next;
    }
    return c;
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
    printf("Press 3 to Count nodes.\n");
    printf("Press 4 to Traverse the linked list.\n");
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
            c = countNodes(head);
            printf("The number of nodes = %d\n",c);
            break;
        case 4:
            traversal(head);
            break;
        default:
            printf("Invalid Input");
            break;
    }
}