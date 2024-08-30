// Write a C program that performs the following operations on
// sparse matrices:
// Addition of Two Sparse Matrices
// Multiplication of Two Sparse Matrices

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
int* convertSparse(int r, int c, int arr[r][c]) {
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
    representation(nz, 3, sarr);
    return sarr;
}
int* sumSparseTriplet(int nz1, int sarr1[nz1][3], int nz2, int sarr2[nz2][3]) {
    int r = (nz1>nz2)? nz1 : nz2;
    int sum[r][3];
    int min = (nz1<nz2)? nz1:nz2;
    int k=0;
    for(int i=0; i<=min; i++, k++) {
        for(int j=0; j<3; j++) {
            sum[k][j] = sarr1[i][j] + sarr2[i][j];
        }
    }
    if(min<nz1) {
        for(int i=min+1; i<=nz1; i++, k++) {
            for(int j=0; j<3; j++) {
                sum[k][j] = sarr1[i][j];
            }
        }
    }
    if(min<nz2) {
        for(int i=min+1; i<=nz2; i++, k++) {
            for(int j=0; j<3; j++) {
                sum[k][j] = sarr2[i][j];
            }
        }
    }
    representation(r, 3, sum);
    return sum;
}
int* multSparseTriplet(int nz1, int sarr1[nz1][3], int nz2, int sarr2[nz2][3]) {
    int r = (nz1>nz2)? nz1 : nz2;
    int mult[r][3];
    int min = (nz1<nz2)? nz1:nz2;
    int k=0;
    for(int i=0; i<=min; i++, k++) {
        for(int j=0; j<3; j++) {
            mult[k][j] = sarr1[i][j] * sarr2[i][j];
        }
    }
    if(min<nz1) {
        for(int i=min+1; i<=nz1; i++, k++) {
            for(int j=0; j<3; j++) {
                mult[k][j] = sarr1[i][j];
            }
        }
    }
    if(min<nz2) {
        for(int i=min+1; i<=nz2; i++, k++) {
            for(int j=0; j<3; j++) {
                mult[k][j] = sarr2[i][j];
            }
        }
    }
    representation(r, 3, mult);
    return mult;
}
int* sumSparse(int r1, int c1, int arr1[r1][c1], int r2, int c2, int arr2[r2][c2]) {
    if(r1 != r2 && c1 != c2) {
        printf("The matrices cannot be added in the given form.\n");
        return NULL;
    }
    int sum[r1][c1];
    for(int i=0; i<=r1; i++) {
        for(int j=0; j<c1; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    representation(r1, c1, sum);
    return convertSparse(r1, c1, sum);
}
int* multSparse(int r1, int c1, int arr1[r1][c1], int r2, int c2, int arr2[r2][c2]) {
    if(c1 != r2) {
        printf("The matrices cannot be multiplied in the given form.\n");
        return NULL;
    }
    int mult[c1][r2];
    for(int i=0; i<=c1; i++) {
        for(int j=0; j<r2; j++) {
            mult[i][j] = 0;
            for (int k = 0; k < r2; k++) {
                mult[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    representation(c1, r2-1, mult);
    return convertSparse(c1, r2-1, mult);
}
void representation(int r, int c, int arr[r][c]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int r1, c1, r2, c2;
    printf("Enter no of rows and columns for the 1st matrix\n");
    scanf("%d%d", &r1, &c1);
    int arr1[r1][c1];
    printf("Enter the %d elements for 1st matrix\n", r1*c1);
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    printf("Enter no of rows and columns for the 2nd matrix\n");
    scanf("%d%d", &r2, &c2);
    int arr2[r2][c2];
    printf("Enter the %d elements for 2nd matrix\n", r2*c2);
    for(int i=0; i<r2; i++) {
        for(int j=0; j<c2; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    for(int i=0; i<r2; i++) {
        for(int j=0; j<c2; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    };
    printf("Sum of Matrices in triplet form: \n");
    int *sum = sumSparse(r1, c1, arr1, r2, c2, arr2);
    printf("Multiplication of Matrices in triplet form: \n");
    int *mult = multSparse(r1, c1, arr1, r2, c2, arr2);
    return 0;
}