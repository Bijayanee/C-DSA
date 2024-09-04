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
    printf("Press 1 to search an element in the list\n");
    printf("Press 2 to sort the list in ascending order\n");
    printf("Press 3 to reverse the list\n");
    printf("Enter your choice: ");
    int ch, el, po;
    scanf("%d",&ch);
    switch (ch){
        case 1:
            printf("Enter the element you want to search for.\n");
            scanf("%d", &el);
            po = search(head,el);
            if(po != -1) 
                printf("The element found at %d position.\n", po);
            else 
                printf("The element is not there in the list.\n");
            break;
        case 2:
            break;
        case 3:
            head = reverse(head);
            break;
        default:
            printf("Invalid Input");
            break;
    }
}