/*
   Write a program that uses your computer to simulate the basic  
   operations of a calculator. Present the user with the following 
   menu:
	1: Add
	2: Subtract
	3: Multiply
	4: Divide
	5: Exit      
   Your program should allow the user to enter a choice along with 2 
   integers and then perform the appropriate computation and output 
   the result to the user. The program should only exit when the user 
   selects option 5.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
   int answer = 0, number1, number2, userChoice;

   // use a do...while() loop 

   do {
      printf("1: Add\n");
      printf("2: Subtract\n");
      printf("3: Multiply\n");
      printf("4: Divide\n");
      printf("5: Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&userChoice);
   

   // use the switch() selection
      switch(userChoice)
      {
         case 1: 
                  printf("Enter number 1: ");
                  scanf("%d",&number1);
                  printf("Enter number 2: ");
                  scanf("%d",&number2);
                  answer = number1 + number2;
                  printf("The sum is: %d\n", answer);
                  break;

         case 2: 
                  printf("Enter number 1: ");
                  scanf("%d",&number1);
                  printf("Enter number 2: ");
                  scanf("%d",&number2);
                  answer = number1 - number2;
                  printf("The difference is: %d\n", answer);
                  break;

         case 3: 
                  printf("Enter number 1: ");
                  scanf("%d",&number1);
                  printf("Enter number 2: ");
                  scanf("%d",&number2);
                  answer = number1 * number2;
                  printf("The product is: %d\n", answer);
                  break;

         case 4: 
                  printf("Enter number 1: ");
                  scanf("%d",&number1);
                  printf("Enter number 2: ");
                  scanf("%d",&number2);
                  answer = number1 / number2;
                  printf("The quotient is: %d\n", answer);
                  break;

         case 5: 
                  printf("Exiting program...");
                  exit(0);
                  break; // unreachable

         default: printf("Invalid selection!");
      }

   } while(true);
}














