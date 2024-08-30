// WAP to add 2 sparse matrix then display their sum
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
void sparse(int r, int c, int arr1[r][c], int arr2[r][c]) {
    int nz1 = noOfNonZeroElements(r, c, arr1);
    int nz2 = noOfNonZeroElements(r, c, arr2);
    int sarr1[nz1][3];
    int sarr2[nz2][3];
    int sr1 = 1, sr2 = 1;
    sarr1[0][0] = r; sarr2[0][0] = r;
    sarr1[0][1] = c; sarr2[0][1] = c;
    sarr1[0][2] = nz1; sarr2[0][2] = nz2;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr1[i][j] != 0) {
                sarr1[sr1][0] = i;
                sarr1[sr1][1] = j;
                sarr1[sr1++][2] = arr1[i][j];
            }
            if(arr2[i][j] != 0) {
                sarr2[sr2][0] = i;
                sarr2[sr2][1] = j;
                sarr2[sr2++][2] = arr2[i][j];
            }
        }
    }
    int min = (nz1<nz2)? nz1:nz2;
    for(int i=0; i<=min; i++) {
        for(int j=0; j<3; j++) {
            //printf("%d ", sarr1[i][j] + sarr2[i][j]);
            //if(j == 2) {
                printf("%d ", sarr1[i][j] + sarr2[i][j]);
            //}
        }
        printf("\n");
    }
    if(min<nz1) {
        for(int i=min+1; i<=nz1; i++) {
            for(int j=0; j<3; j++) {
                printf("%d ", sarr1[i][j]);
            }
            printf("\n");
        }
    }
    if(min<nz2) {
        for(int i=min+1; i<=nz2; i++) {
            for(int j=0; j<3; j++) {
                printf("%d ", sarr2[i][j]);
            }
            printf("\n");
        }
    }
}
int main() {
    int r, c;
    printf("Enter no of rows and columns for the matrix\n");
    scanf("%d%d", &r, &c);
    int arr1[r][c];
    printf("Enter the %d elements for 1st matrix\n", r*c);
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    int arr2[r][c];
    printf("Enter the %d elements for 2nd matrix\n", r*c);
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    sparse(r, c, arr1, arr2);
    return 0;
}