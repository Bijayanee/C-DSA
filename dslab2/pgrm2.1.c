// Wap to create a 1-d array of n elements and perform the following menu based operations using funtion.
// a. insert a given element at specific position.
// b. delete an element from a specific position of the array.
// c. linear search to search an element
// d. traversal of the array

#include<stdio.h>
void insert(int e, int p, int n, int arr[n]) {
    for(int i=n; i>=p-1; i--) {
        arr[i+1] = arr[i];
    }
    arr[p] = e;
    printf("Insertion suscessful\n");
    for(int i=0; i<=n; i++) {
        printf("%d  ", arr[i]);
    }
}
void delete(int p, int n, int arr[n]) {
    for(int i=p; i<n-1; i++) {
        arr[i] = arr[i+1];
    }
    printf("Deletion suscessful\n");
    for(int i=0; i<n-1; i++) {
        printf("%d  ", arr[i]);
    }
}
void search(int e, int n, int arr[n]) {
    for(int i=0; i<n; i++) {
        if(arr[i] == e) {
            printf("Element found at %d position", (i+1));
            return;
        }
    }
    printf("Element not found");
    return;
}
void traversal(int n, int arr[n]) {
    for(int i=0; i<n; i++) {
        printf("%d  ", arr[i]);
    }
}
int main() {
    int n, ch, e, p;
    printf("Enter the number of elements you want to input\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the %d elements\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter 1 to insert a given element at specific position\n");
    printf("Enter 2 to delete an element from a specific position of the array\n");
    printf("Enter 3 to linear search to search an element\n");
    printf("Enter 4 to traversal of the array\n");
    printf("Enter your choice\n");
    scanf("%d", &ch);
    switch(ch) {
        case 1:
            printf("Enter the element and the position you want to insert\n");
            scanf("%d%d", &e, &p);
            insert(e, p, n, arr);
            break;
        case 2:
            printf("Enter the position you want to delete\n");
            scanf("%d", &p);
            delete(p, n, arr);
            break;
        case 3:
            printf("Enter the element you want to search\n");
            scanf("%d", &e);
            search(e, n, arr);
            break;
        case 4:
            traversal(n, arr);
            break;
        default:
            printf("Invalid Input\n");
    }
    return 0;
}
