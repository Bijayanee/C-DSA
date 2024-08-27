//WAP to read 2 nos and compare the nos using function call by address
#include <stdio.h>
void compare(int *a, int *b) {
  if (*a > *b) {
    printf("The greater number is %d", *a);
  }
  else if(*a < *b) {
      printf("The greater number is %d", *b);
  }
  else {
    printf("Both the numbers are equal");
  }
}
int main() {
  int a, b;
  printf("Enter two numbers\n");
  scanf("%d%d", &a, &b);
  compare(&a, &b);
  return 0;
}

