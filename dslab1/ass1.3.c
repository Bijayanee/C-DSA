//WAP to create a structure to store the information of n number of employees. Employee's information includes data member: id, name, designation, basic_salary, hra%, da%. Display the information of employees with gross salary. use array of structure.
#include <stdio.h>
struct employee {
  int id;
  char name[50];
  char designation[50];
  float basic_salary, hra, da, gross_salary;
};
int main(){ 
  int n,i;
  printf("Enter the number of employees\n");
  scanf("%d",&n);
  struct employee emp[n];
  for(i=0;i<n;i++) {
    printf("Enter the details of employee %d\n",i+1);
    printf("Enter the id\n");
    scanf("%d",&emp[i].id);
    printf("Enter the name\n");
    scanf("%s",emp[i].name);
    printf("Enter the designation\n");
    scanf("%s",emp[i].designation);
    printf("Enter the basic salary\n");
    scanf("%f",&emp[i].basic_salary);
    printf("Enter the hra percentage\n");
    scanf("%f",&emp[i].hra);
    printf("Enter the da percentage\n");
    scanf("%f",&emp[i].da);
    emp[i].gross_salary = emp[i].basic_salary + (emp[i].basic_salary * emp[i].hra / 100 + emp[i].basic_salary * emp[i].da / 100);
  }
  printf("The details of employees are\n");
  for(i=0;i<n;i++) {
    printf("The details of employee %d\n",i+1);
    printf("The id is %d\n",emp[i].id);
    printf("Name of the employee: %s\n", emp[i].name);
    printf("Designation of the employee: %s\n", emp[i].designation);
    printf("The basic salary is %f\n", emp[i].basic_salary);
    printf("The hra percentage is %f\n", emp[i].hra);
    printf("The da percentage is %f\n", emp[i].da);
    printf("The gross salary is %f\n", emp[i].gross_salary);
  }
  return 0;
}