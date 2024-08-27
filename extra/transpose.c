#include<stdio.h>
void transpose(int n, int a[n][n]) {
    for(int i=0; i<n/2; i++) {
        for(int j=0; j<n; j++) {
            int dup = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = dup;
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
    transpose(n, arr);
    return 0;
}