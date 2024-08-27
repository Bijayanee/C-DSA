//Write a menu driven program to create a structure to represent complex number and perform the following using functions.1.Addition of two complex numbers using call by value and multiply two complex numbers using call by reference.
#include<stdio.h>
struct complex {
  int real;
  int img;
};
void add(struct complex c1, struct complex c2) {
  struct complex c3;
  c3.real = c1.real + c2.real;
  c3.img = c1.img + c2.img;
  printf("The sum of the complex numbers is %d + %di\n", c3.real, c3.img);
}
void mlt(struct complex c1, struct complex c2) {
  struct complex c3;
  c3.real = c1.real * c2.real - c1.img * c2.img;
  c3.img = c1.real * c2.img + c1.img * c2.real;
  printf("The product of the complex numbers is %d + %di\n", c3.real, c3.img);
}
int main(){
  struct complex c1,c2;
  printf("Enter the real and imaginary parts of the first complex number\n");
  scanf("%d%d",&c1.real,&c1.img);
  printf("Enter the real and imaginary parts of the second complex number\n");
  scanf("%d%d",&c2.real,&c2.img);
  int choice;
  printf("Enter your choice\nPress 1 for addition\nPress 2 for multiplication\n");
  scanf("%d",&choice);
  switch(choice) {
    case 1: add(c1,c2);
            break;
    case 2: mlt(c1,c2);
            break;
    default: printf("Invalid choice");
  }
}