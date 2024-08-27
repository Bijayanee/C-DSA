//WAP to create an array of n elements using dynamic allocation. Calculate the sum of all prime elements of the array using function and dealloacte the memory of the array after its use.
#include<stdio.h>
int sum(int n, int arr[]) {
  int s=0;
  for(int i=0; i<n; i++) {
    int j;
    for(j=2; j<arr[i]; j++) {
      if(arr[i]%j==0) {
        break;
      }
    }
    if(j==arr[i]) {
      s+=arr[i];
    }
  }
  return s;
}
int main () {
  int n,i,j;
  printf("Enter the number of elements\n");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the elements\n");
  for(int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
  }
  int s = sum(n, arr);
  printf("The sum of all prime elements is %d\n",s);
  return 0;
}