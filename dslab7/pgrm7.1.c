// Write a menu driven program to create a stack using array and perform the following
// operation using function
// a. Push
// b. Pop
// c. check stack is empty or not
// d. check stack is full or not
// e. display stack elements

#include<stdio.h>
#include <stdbool.h>

struct Stack{
    int top;
    int *arr;
    int size;
};

struct Stack *ptr;

void arrSize(int s){
    ptr = (struct Stack*)malloc(sizeof(struct Stack));
    ptr -> size = s;
    ptr -> top = -1;
    ptr -> arr = (int*)malloc(s*sizeof(int));
}

bool isEmpty(){
    return (ptr->top == -1);
}

bool isFull(){
    return (ptr->top == ptr->size-1);
}

void push(int data){
    if(isFull()){
        printf("Stack Full");
        return;
    }
    ptr->top = ptr->top+1;
    ptr->arr[ptr->top] = data;
}

int pop(){
    if(isEmpty()){
        printf("Empty Stack");
        return 0; //assuming 0 is not a value in the stack
    }
    ptr->top = ptr->top-1;
    return ptr->arr[ptr->top--];
}

void display(){
    if(isEmpty()){
        printf("Empty Stack");
        return;
    }
    for(int i=ptr->top; i>-1; i--){
        printf("%d\t", ptr->arr[i]);
    }
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
            break;
        case 2:
            printf("%d", pop());
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
