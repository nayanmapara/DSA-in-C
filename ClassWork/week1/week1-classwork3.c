//Program to read 2 numbers and determine if one is larger or if they are equal
#include <stdio.h>
int main (void)
{
   
   int number1=0, number2=0;
   
   printf("Enter First Integer: ");
   scanf("%d", &number1);
   
   printf("Enter Second Integer: ");
   scanf("%d", &number2);

   /* determine if first number is greater */
   if (number1>number2)
   {
    printf("Number 1:%d is greater than Number 2:%d\n", number1, number2);
   }

   /* determine if second number is greater*/
   else if (number2>number1)
   {
    printf("Number 2:%d is greater than Number 1:%d\n", number2, number1);
   }
   
   
   /* determine both numbers are equal     */  
   else
   {
    printf("Number 1:%d is equal to Number 2:%d\n", number1, number2);
   }
   
   
 } // main function ends here
