#include<stdio.h>
#include <stdlib.h>

void bubbleSort(int n, int arr[n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
/* Bubble Sort
    Time Complexity:
        In worst case O(n^2)
        In average case θ(n^2)
        In best case Ω(n)
*/

void insertionSort(int n, int arr[n]){
    for(int i=0; i<n-1; i++){
        for(int j=i; j>=0; j--){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            else break;
        }
    }
}
/* Insertion Sort
    Time Complexity:
        In worst case O(n^2)
        In average case θ(n^2)
        In best case Ω(n)
*/

void selectionSort(int n, int arr[n]){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
/* Selection Sort
    Time Complexity:
        In worst case O(n^2)
        In average case θ(n^2)
        In best case Ω(n)
*/

void quickSortR(int n, int arr[n], int start, int end){
    if(start >= end){
        return;
    }
    int s = start, e = end;
    int m = s+(e-s)/2;
    int pivot = arr[m];
    while(s <= e) {
        while(arr[s] < pivot){
            s++;
        }
        while(arr[e] > pivot){
            e--;
        }
        if(s <= e){
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++; e--;
        }
    }
    quickSortR(n, arr, start, e);
    quickSortR(n, arr, s, end);
}
void quickSort(int n, int arr[n]){
    quickSortR(n, arr, 0, n-1);
}
/* Quick Sort
    Time Complexity:
        In worst case O(n^2)
        In average case θ(nlogn)
        In best case Ω(nlogn)
*/

void merge(int n, int arr[n], int start, int end){
    int merg[end-start+1];
    int mid = start+(end-start)/2;
    int i = start,  j = mid+1, k = 0;
    while(i<=mid && j<=end){
        if(arr[i] < arr[j]){
            merg[k++] = arr[i++];
        } else {
            merg[k++] = arr[j++];
        }
    }
    while(i <= mid){
        merg[k++] = arr[i++];
    }
    while(j <= end){
        merg[k++] = arr[j++];
    }
    for(int c=0; c<end-start+1; c++){
        arr[start+c] = merg[c];
    }
}
void mergeSortR(int n, int arr[n], int start, int end){
    if(start >= end){
        return;
    }
    int mid = start + (end-start)/2;
    mergeSortR(n, arr, start, mid);
    mergeSortR(n, arr, mid+1, end);
    merge(n, arr, start, end);
}
void mergeSort(int n, int arr[n]){
    mergeSortR(n, arr, 0, n-1);
}
/* Merge Sort
    Time Complexity:
        In worst case O(nlogn)
        In average case θ(nlogn)
        In best case Ω(nlogn)
*/

void display(int n, int arr[n]){
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}

void main(){
    int n,ch;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter %d elements:\n",n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("1. Bubble sort:\n");
    printf("2. Insertion sort:\n");
    printf("3. Selection sort:\n");
    printf("4. Quick sort:\n");
    printf("5. Merge sort:\n");
    scanf("%d", &ch);
    switch (ch){
        case 1:
            bubbleSort(n, arr);
            display(n, arr);
            break;
        case 2:
            insertionSort(n, arr);
            display(n, arr);
            break;
        case 3:
            selectionSort(n, arr);
            display(n, arr);
            break;
        case 4:
            quickSort(n, arr);
            display(n, arr);
            break;
        case 5:
            mergeSort(n, arr);
            display(n, arr);
            break;
        default:
            printf("Invalid Input");
            break;
    }
}