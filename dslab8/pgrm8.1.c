// Write a menu driven program to create a linear queue using array and perform
// Enqueue, Dequeue, Traverse, IsEmpty, IsFull operations.

#include <stdio.h>
#include <stdbool.h>

struct Queue{
    int front;
    int rear;
    int *arr;
    int size;
};

struct Queue *ptr;

void arrSize(int s){
    ptr = (struct Stack*)malloc(sizeof(struct Queue));
    ptr -> size = s + 2;
    ptr -> front = -1;
    ptr -> rear = -1;
    ptr -> arr = (int*)malloc(ptr->size*sizeof(int));
}

bool isEmpty() {
    return (ptr->front == -1 || ptr->front > ptr->rear);
}

bool isFull() {
    return (ptr->rear == ptr->size - 1);
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue full");
        return;
    }
    if (ptr->front == -1) 
        ptr->front = 0;
    ptr->arr[++ptr->rear] = element;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    int data = ptr->arr[ptr->front++];
    if (ptr->front > ptr->rear) { 
        ptr->front = ptr->rear = -1;
    }
    return data;
}

void traverse() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    for (int i = ptr->front; i <= ptr->rear; i++) {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}

void main(){
    int s;
    printf("Enter number of elements: ");
    scanf("%d",&s);
    arrSize(s);
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