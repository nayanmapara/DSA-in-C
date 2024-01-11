// Name: Nayan

// Program to determine whether the first integer is a multiple of the second integer

#include <stdio.h>

int main (void)
{
   int number1, number2;
   
   // Number 1   
   printf("Enter The Integer-1: ");
   scanf("%d", &number1);
   
   // Number 2   
   printf("Enter The Integer-2: ");
   scanf("%d", &number2);
   
   /* determine if number1 is a multiple of number2 */
   if (number1 % number2 == 0) 
   {
      printf("Integer-1 (%d) is a multiple of Integer-2 (%d)\n", number1, number2);
   }
   
   /* determine if number is odd  */
   else
   {
        printf("Integer-1 (%d) is NOT a multiple of Integer-2 (%d)\n", number1, number2);
   }  
}
