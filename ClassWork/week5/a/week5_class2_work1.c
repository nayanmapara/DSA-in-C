#include <stdio.h>

// structure definition with student id, name, gender, height 
struct student
{
    int id;
    char name[20];
    char gender;
    float height;
};

// rename the structure for convenient usage
typedef struct student Student;

int main ()
{
   /* Structure declaration & Initialisation */

   Student x = {123, "Jim", 'm', 5.7}; 
   //Student y;
   //Student *xPtr = &x;
   // int i;

   /* Structure usage with the dot-operator*/
   printf("The Id is : %d \n", x.id); 
   printf("The Name is : %s \n", x.name);
   printf("The Gender is : %c \n",x.gender);
   printf("The Height is : %f \n",x.height);
   
   /* Structure usage with the pointer operator old standard*/
   //printf("The Id is : %d \n", (*xPtr).id); 
   //printf("The Name is : %s \n", (*xPtr).name);
   //printf("The Gender is : %c \n",(*xPtr).gender);
   //printf("The Height is : %f \n",(*xPtr).height);

   /* Structure usage with the pointer arrow-operator new standard*/
   //printf("The Id is : %d \n", xPtr->id); 
   //printf("The Name is : %s \n", xPtr->name);
   //printf("The Gender is : %c \n",xPtr->gender);
   //printf("The Height is : %f \n",xPtr->height);

   /* Determining the size of the structure type "Student"*/
   //printf("The Size of the Student Type is %ld\n", sizeof(Student));
   
   /* Read new info into Student Y and Print the information*/  
   //printf("Enter ID ");
   //scanf("%d", &y.id);

   //printf("Enter Name ");
   //scanf("%s", y.name);

   //printf("Enter Gender ");
   //scanf(" %c", &y.gender); // note the space before %c; try using getchar()

   //printf("Enter Height ");
   //scanf("%f", &y.height);

   //printf("ID for Student Y is %d \n", y.id);
   //printf("Name for Student Y is %s \n ", y.name);
   //printf("Gender for Student Y is %c \n", y.gender);
   //printf("Height for Student Y is %f \n", y.height);
}



