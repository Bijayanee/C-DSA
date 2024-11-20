// Write a menu driven program to implement linear queue operations such as
// Enqueue, Dequeue, IsEmpty, Traverse using single linked list.

#include <stdio.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

struct Queue *ptr;

void listSize(){
    ptr = (struct Queue*)malloc(sizeof(struct Queue));
    ptr -> front = NULL;
    ptr -> rear = NULL;
}

struct Node* create(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Queue));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty() {
    return (ptr -> front == NULL);
}

bool isFull(){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Queue));
    return (newNode == NULL);
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue full\n");
        return;
    }
    struct Node* newNode = create(data);
    if (ptr -> rear == NULL) {
        ptr -> front = ptr -> rear = newNode;
    } else {
        ptr->rear->next = newNode;
        ptr->rear = newNode;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    struct Node* temp = ptr->front;
    int data = ptr->front->data;
    ptr->front = ptr->front->next;
    if (ptr->front == NULL) {
        ptr->rear = NULL;
    }
    free(temp);
    return data;
}

void traverse() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    struct Node* temp = ptr->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main(){
    int s;
    printf("Enter number of elements: ");
    scanf("%d",&s);
    listSize();
    printf("Enter %d elements:\n",s);
    for(int i=0; i<s; i++){
        int d;
        scanf("%d", &d);
        enqueue(d);
    }
    printf("Press 1 to Enqueue.\n");
    printf("Press 2 to Dequeue.\n");
    printf("Press 3 to Traverse.\n");
    printf("Press 4 to IsEmpty.\n");
    printf("Press 5 to IsFull.\n");
    printf("Enter your choice: ");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Enter the data: ");
            int d;
            scanf("%d", &d);
            enqueue(d);
            traverse();
            break;
        case 2:
            printf("%d\n", dequeue());
            traverse();
            break;
        case 3:
            traverse();
            break;
        case 4:
            if(isEmpty()){
                printf("Queue empty");
            } else {
                printf("Queue not empty");
            }
            break;
        case 5:
            if(isFull()){
                printf("Queue full");
            } else {
                printf("Queue not full");
            }
            break;
        default:
            printf("Invalid Input");
            break;
    }
}