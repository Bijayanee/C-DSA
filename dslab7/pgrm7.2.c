// Write a menu driven program to create a stack using linked list and perform the
// following operation using function
// a. Push
// b. Pop
// c. IsEmpty
// d. display the stack elements

#include<stdio.h>
#include <stdbool.h>

struct Node{
    struct Node* next;
    int data;
};

struct Stack{
    struct Node* top;
};

struct Stack *ptr;

void listSize(){
    ptr = (struct Stack*)malloc(sizeof(struct Stack));
    ptr -> top = NULL;
}

struct Node* create(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(){
    return (ptr->top == NULL);
}

bool isFull(){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Stack));
    return (newNode == NULL);
}

void push(int data){
    if(isFull()){
        printf("Stack Full");
        return;
    }
    struct Node* newNode = create(data);
    newNode->next = ptr->top;
    ptr->top = newNode;
}

int pop(){
    if(isEmpty()){
        printf("Empty Stack");
        return 0; //assuming 0 is not a value in the stack
    }
    struct Node* temp = ptr->top;
    int data = temp->data;
    ptr->top = ptr->top->next;
    free(temp);
    return data;
}

void display(){
    if(isEmpty()){
        printf("Empty Stack");
        return;
    }
    struct Node* node = ptr->top;
    while(node != NULL){
        printf("%d\t", node->data);
        node = node->next;
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
        push(d);
    }
    printf("Press 1 to Push a data to the stack.\n");
    printf("Press 2 to Pop a data to the stack.\n");
    printf("Press 3 to check stack is empty or not.\n");
    printf("Press 4 to check stack is full or not.\n");
    printf("Press 5 to display stack elements.\n");
    printf("Enter your choice: ");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Enter the data: ");
            int d;
            scanf("%d", &d);
            push(d);
            display();
            break;
        case 2:
            printf("%d", pop());
            display();
            break;
        case 3:
            if(isEmpty()){
                printf("Stack empty");
            } else {
                printf("Stack not empty");
            }
            break;
        case 4:
            if(isFull()){
                printf("Stack full");
            } else {
                printf("Stack not full");
            }
            break;
        case 5:
            display();
            break;
        default:
            printf("Invalid Input");
            break;
    }
}
