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
