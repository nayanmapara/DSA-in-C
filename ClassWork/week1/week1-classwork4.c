// Program to determine whether an integer is odd or even 

#include <stdio.h>

int main (void)
{
   int number;
   
   printf("Enter The Integer: ");
   scanf("%d", &number);
   
   /* determine if number is even */
   if (number % 2 == 0) 
   {
      printf("%d is even\n", number);
   }
   
   /* determine if number is odd  */
   else
   {
      printf("%d is odd\n", number);
   }  
}
