// Write a program to create a single linked list of n nodes and
// perform the following menu-based operations on it using
// function:
// 1. Traverse the linked list
// 2. Insert an element at the end
// 3. Insert an element in the beginning
// 4. Insert at any position

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
    while (ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
struct Node* insertEnd(struct Node* head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data you want to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        return head;
    }
    struct Node* ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    printf("Insertion successful\n");
    traversal(head);
    return head;
}
struct Node* insertStart(struct Node* head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data you want to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    printf("Insertion successful\n");
    traversal(head);
    return head;
}
struct Node* insertPosition(struct Node* head, int p) {
    if(head == NULL) {
        printf("Empty List! Can't add element at %d position\n",p);
        return head;
    }
    if(p==1) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data you want to insert");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        printf("Insertion successful\n");
        traversal(head);
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
    printf("Insertion successful\n");
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
    printf("Press 1 to Traverse the linked list\n");
    printf("Press 2 to Insert an element at the end\n");
    printf("Press 3 to Insert an element in the beginning\n");
    printf("Press 4 to Insert at any position\n");
    printf("Enter your choice: ");
    int ch;
    
    scanf("%d",&ch);
    switch (ch){
        case 1:
            traversal(head);
            break;
        case 2:
            head = insertEnd(head);
            break;
        case 3:
            head = insertStart(head);
            break;
        case 4:
            printf("Enter the position you want to insert at:");
            scanf("%d",&p);
            head = insertPosition(head,p);
            break;
        default:
            printf("Invalid Input");
            break;
    }
}

























// struct Node* insertPosition(struct Node* head, int p) {
//     if(head == NULL) {
//         printf("Empty List! Can't add element at %d position\n",p);
//         return head;
//     }
//     if(p==1) {
//         struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//         printf("Enter the data you want to insert");
//         scanf("%d", &newNode->data);
//         newNode->next = NULL;
//         printf("Insertion successful\n");
//         traversal(head);
//         return newNode;
//     }
//     struct Node* ptr = head;
//     int c=0;
//     while(c<p-2 && ptr->next!=NULL) {
//         c++;
//         ptr = ptr->next;
//     }
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     printf("Enter the data you want to insert: ");
//     scanf("%d", &newNode->data);
//     newNode->next = ptr->next;
//     ptr->next = newNode;
//     printf("Insertion successful\n");
//     traversal(head);
//     return head;
// }