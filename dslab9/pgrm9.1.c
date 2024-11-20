// Write a menu driven program to implement Deques (both Inputrestricted and
// output-restricted) and performed operations such as Enqueue, Dequeue, Peek,
// IsEmpty, IsFull using static array.

#include <stdio.h>

struct Deque {
    int front;
    int rear;
    int size;
    int *deque;
};

struct Deque* ptr;

void initialize(int s){
    ptr = (struct Deque*)malloc(sizeof(struct Deque));
    ptr->size = s;
    ptr->front = ptr->rear = -1;
    ptr->deque = (int*)malloc(ptr->size*sizeof(int));
}

int isEmpty() {
    return (ptr->front == -1);
}

int isFull() {
    // return ((ptr->front == 0 && ptr->rear == ptr->size - 1) || (ptr->front == ptr->rear + 1));
    return ((ptr->rear+1) % ptr->size == ptr->front);
}

void enqueueRear(int value) {
    if (isFull()) {
        printf("Deque full.\n");
        return;
    }
    if (isEmpty()) {
        ptr->front = ptr->rear = 0;
    } else {
        ptr->rear = (ptr->rear+1) % ptr->size;
    }
    // } else if (ptr->rear == ptr->size - 1) {
    //     ptr->rear = 0;
    // } else {
    //     ptr->rear++;
    // }
    ptr->deque[ptr->rear] = value; 
}

void enqueueFront(int value) {
    if (isFull()) {
        printf("Deque full.\n");
        return;
    }
    if (isEmpty()) {
        ptr->front = ptr->rear = 0;
    } else {
        ptr->front = (ptr->front-1 + ptr->size) % ptr->size;
    }
    // } else if (ptr->front == 0) {
    //     ptr->front = ptr->size - 1;
    // } else {
    //     ptr->front--;
    // }
    ptr->deque[ptr->front] = value;
}

int dequeueFront() {
    if (isEmpty()) {
        printf("Deque empty.\n");
        return;
    }
    int value = ptr->deque[ptr->front];
    if (ptr->front == ptr->rear) {
        ptr->front = ptr->rear = -1;
    } else {
        ptr->front = (ptr->front + 1) % ptr->size;
    }
    // } else if (ptr->front == ptr->size - 1) {
    //     ptr->front = 0;
    // } else {
    //     ptr->front++;
    // }
    return value;
}

void dequeueRear() {
    if (isEmpty()) {
        printf("Deque empty.\n");
        return;
    }
    int value = ptr->deque[ptr->rear];
    if (ptr->front == ptr->rear) {
        ptr->front = ptr->rear = -1;
    } else {
        ptr->rear = (ptr->rear-1 + ptr->size) % ptr->size;
    }
    // } else if (ptr->rear == 0) {
    //     ptr->rear = ptr->size - 1;
    // } else {
    //     ptr->rear--;
    // }
    return value;
}

int peekFront() {
    if (isEmpty()) {
        printf("Deque empty.\n");
        return -1;
    }
    return ptr->deque[ptr->front];
}

int peekRear() {
    if (isEmpty()) {
        printf("Deque empty.\n");
        return -1;
    }
    return ptr->deque[ptr->rear];
}

void traverse() {
    if (isEmpty()) {
        printf("Deque empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = ptr->front;
    do{
        printf("%d ", ptr->deque[i]);
        i = (i + 1) % ptr->size;
    } while(i != ptr->rear);
    printf("\n");
}

void userChoice(int option){
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
            if(option == 2){
                int ans;
                printf("Press 1 to Enqueue at rear.\n");
                printf("Press 1 to Enqueue t front.\n");
                printf("Enter your choice: ");
                scanf("%d", &ans);
                if(ans == 1){
                    enqueueRear(d);
                } else if(ans == 2) {
                    enqueueFront(d);
                } else {
                    printf("invalidinput");
                }
            } else {
                enqueueRear(d);
            }
            traverse();
            break;
        case 2:
            if(option == 1){
                int ans;
                printf("Press 1 to Dequeue at rear.\n");
                printf("Press 1 to Dequeue at front.\n");
                printf("Enter your choice: ");
                scanf("%d", &ans);
                if(ans == 1){
                    dequeueRear();
                } else if(ans == 2) {
                    dequeueFront();
                } else {
                    printf("invalid input");
                }
            } else {
                dequeueFront();
            }
            traverse();
            break;
        case 3:
            traverse();
            break;
        case 4:
            if(isEmpty()){
                printf("Deque empty");
            } else {
                printf("Deque not empty");
            }
            break;
        case 5:
            if(isFull()){
                printf("Deque full");
            } else {
                printf("Deque not full");
            }
            break;
        default:
            printf("Invalid Input");
            break;
    }
}

void main(){
    int s, choice;
    printf("Press 1 for Inputrestricted Deque");
    printf("Press 1 for Inputrestricted Deque");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    if (choice!=1 || choice!=2){
        printf("Invalid Input");
        return;
    }
    printf("Enter number of elements: ");
    scanf("%d",&s);
    arrSize(s);
    printf("Enter %d elements:\n",s);
    for(int i=0; i<s; i++){
        int d;
        scanf("%d", &d);
        enqueueRear(d);
    }
    userChoice(choice);
}