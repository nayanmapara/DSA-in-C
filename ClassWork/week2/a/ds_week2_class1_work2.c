/* 
   Part B: Use methods to implement:

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

// function prototype or declaration
int add(int number1, int number2);
int subtract(int number1, int number2);
int multiply(int number1, int number2);
int divide(int number1, int number2);

int main (void)
{
  int number1, number2, choice;
  int answer = 0;
  do{
     puts("1: Add");
     puts("2: Subtract");
     puts("3: Multiply");
     puts("4: Divide");
     puts("5: Exit");
     
     puts("Enter Your Choice");
     scanf("%d", &choice);

     switch(choice)
     {
      case 1: printf("Enter First Number ");
              scanf("%d",&number1);
              printf("Enter First Number ");
              scanf("%d",&number2);
              
              answer = add(number1,number2);  // function call

              printf("The Sum is %d ", answer);
              break;

      case 2: printf("Enter First Number ");
              scanf("%d",&number1);
              printf("Enter First Number ");
              scanf("%d",&number2);

              answer = subtract(number1,number2);

              printf("The difference is %d ", answer);
              break;
      
      case 3: printf("Enter First Number ");
              scanf("%d",&number1);
              printf("Enter First Number ");
              scanf("%d",&number2);

              answer = multiply(number1,number2);

              printf("The Product is %d ", answer);
              break;

      case 4: printf("Enter First Number ");
              scanf("%d",&number1);
              printf("Enter First Number ");
              scanf("%d",&number2);
   
              answer = divide(number1,number2);

              printf("The Quotient is %d ", answer);
              break;

      case 5: puts("Program Exiting... Goodbye");
              exit(0);
              break;

      default:puts("Invalid Choice... Try Again");
              break;
     }
     puts("");
   }while(1);  

}

// ************Function Definitions *****************
int add(int number1, int number2) /*Function Header*/
{/*Function Body begins Here*/
   return number1 + number2;
}/*Function Body Ends Here*/

int subtract(int number1, int number2) /*Function Header*/
{
   return number1 - number2;
}

int multiply(int number1, int number2) /*Function Header*/
{
   return number1 * number2;
}

int divide(int number1, int number2) /*Function Header*/
{
   return number1 / number2;
}



                

