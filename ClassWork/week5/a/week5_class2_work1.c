#include <stdio.h>

// structure definition with student id, name, gender, height 
typedef struct test1{ //*...*****... Padding is added to each member such that it gets to multiples of 4(4,8,12,16,20,24,28,32)
   char a; // 1 byte
   int b; // 4 bytes
   char c; //1 byte
}Test1;

typedef struct test2{ //**..**** // If the memory takes up less than 4, they will be saved in the same 4 byte memory
   char a; // 1 byte
   char b; // 1 byte
   int c; // 4 bytes
}Test2;

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
   Student *xPtr = &x;
   // int i;

   /* Structure usage with the dot-operator*/
   // printf("The Id is : %d \n", x.id); 
   // printf("The Name is : %s \n", x.name);
   // printf("The Gender is : %c \n",x.gender);
   // printf("The Height is : %.2f \n",x.height);
   
   /* Structure usage with the pointer operator old standard*/
   // printf("The Id is : %d \n", (*xPtr).id); 
   // printf("The Name is : %s \n", (*xPtr).name);
   // printf("The Gender is : %c \n",(*xPtr).gender);
   // printf("The Height is : %.2f \n",(*xPtr).height);

   /* Structure usage with the pointer arrow-operator new standard*/
   printf("The Id is : %d \n", xPtr->id); 
   printf("The Name is : %s \n", xPtr->name);
   printf("The Gender is : %c \n",xPtr->gender);
   printf("The Height is : %.2f \n",xPtr->height);

   /* Determining the size of the structure type "Student"*/
   printf("The Size of the Student Type is %ld\n", sizeof(Student));
   printf("The Size of the Test1 Type is %ld\n", sizeof(Test1));
   printf("The Size of the Test2 Type is %ld\n", sizeof(Test2));
   /* Read new info into Student Y and Print the information*/  
   // printf("Enter ID: ");
   // scanf("%d", &y.id);

   // printf("Enter Name: ");
   // scanf("%s", y.name);

   // printf("Enter Gender: ");
   // scanf(" %c", &y.gender); // note the space before %c; try using getchar()

   // printf("Enter Height: ");
   // scanf("%f", &y.height);

   // printf("ID for Student Y is %d \n", y.id);
   // printf("Name for Student Y is %s \n ", y.name);
   // printf("Gender for Student Y is %c \n", y.gender);
   // printf("Height for Student Y is %.2f \n", y.height);
}