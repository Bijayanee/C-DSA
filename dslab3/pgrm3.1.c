// WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
// Sample Input:
// Enter size of the sparse matrix: 4 5
// Enter elements of sparse matrix: 0 0 33 0 0 0 17 0 0 0 0 0 0 46 0 0 0 0 0 51
// Sample Output:
// sparse matrix in 3-tuple format
// 4 5 4
// 0 2 33
// 1 1 17
// 2 3 46
// 3 4 51
#include<stdio.h>
int noOfNonZeroElements(int r, int c, int arr[r][c]) {
    int nonZero=0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j]!=0) {
                nonZero++;
            }
        }
    }
    return nonZero;
}
void sparse(int r, int c, int arr[r][c]) {
    int nz = noOfNonZeroElements(r, c, arr);
    int sarr[nz][3];
    int sr = 1;
    sarr[0][0] = r;
    sarr[0][1] = c;
    sarr[0][2] = nz;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j] != 0) {
                sarr[sr][0] = i;
                sarr[sr][1] = j;
                sarr[sr++][2] = arr[i][j];
            }
        }
    }
    for(int i=0; i<nz; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", sarr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int r, c;
    printf("Enter no of rows and columns for the matrix\n");
    scanf("%d%d", &r, &c);
    int arr[r][c];
    printf("Enter the %d elements\n", r*c);
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    // for(int i=0; i<r; i++) {
    //     for(int j=0; j<c; j++) {
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    sparse(r, c, arr);
    return 0;
}


















    
    // for(int i=0; i<r; i++) {                    // this code is not correct
    //     for(int j=0; j<c; j++) {
    //         if(arr[i][j] != 0) {
    //             sarr[i+1][0] = i;
    //             sarr[i+1][1] = j;
    //             sarr[i+1][2] = arr[i][j];
    //         }
    //     }
    // }