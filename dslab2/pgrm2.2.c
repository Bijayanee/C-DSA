// 2.2 Write a program to perform the following operations on a given
// square matrix using functions:
// i. Find the no.of nonzero elements
// ii. Display upper triangular matrix
// iii. Display the elements of just above and below the main diagonal
#include<stdio.h>
int noOfNonZeroElements(int n, int arr[n][n]) {
    int c=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j]!=0) {
                c++;
            }
        }
    }
    return c;
}
void upperTriangularMatrix(int n, int arr[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                printf("%d ", arr[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void elementsAboveBelowDiagonal(int n, int arr[n][n]) {
    printf("Elements just above the main diagonal: ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i][i + 1]);
    }
    printf("\n");
    printf("Elements just below the main diagonal: ");
    for (int i = 1; i < n; i++) {
        printf("%d ", arr[i][i - 1]);
    }
    printf("\n");
}
int main() {
    int n, ch;
    printf("Enter the size of the square matrix\n");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the %d elements\n", n*n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Enter 1 to Find the no.of nonzero elements\n");
    printf("Enter 2 to Display upper triangular matrix\n");
    printf("Enter 3 to Display the elements of just above and below the main diagonal\n");
    printf("Enter your choice\n");
    scanf("%d", &ch);
    switch(ch) {
        case 1:
            printf("the no.of nonzero elements = %d", noOfNonZeroElements(n, arr));
            break;
        case 2:
            upperTriangularMatrix(n, arr);
            break;
        case 3:
            elementsAboveBelowDiagonal(n, arr);
            break;
        default:
            printf("Invalid Input\n");
    }
    return 0;
}