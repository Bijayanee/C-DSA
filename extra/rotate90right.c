#include<stdio.h>
void matrixRotate90Right(int n, int a[n][n]) {
    int b[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            b[i][j] = a[n-1-j][i];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}
void matrixRotate90RightInPlace(int n, int a[n][n]) {
    int b[n][n];
    for(int i=0; i<n/2; i++) {
        for(int j=i; j<n-1; j++) {
            int dup = a[i][j];
            a[i][j] = a[n-1-i][j];
            a[n-1-i][j] = a[n-1-i][n-1-j];
            a[n-1-i][n-1-j] = a[n-1-j][n-1-i];
            a[n-1-j][n-1-i] = dup;
            // a[i][n-1-j] = dup;
            // int dup = a[i][j];
            // a[i][j] = a[n-1-i][j-1];
            // a[n-1-i][j-1] = a[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the size of the square matrix\n");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the %d elements\n", n*n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("-------------\n");
    //matrixRotate90Right(n, arr);
    matrixRotate90RightInPlace(n, arr);
    return 0;
}