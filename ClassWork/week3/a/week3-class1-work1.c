/* Activities to perform
   1 - declare and intitialise array of integers size 10 to zeros
   2 - read 10 integers from the user into the array
   3 - sum the numbers in the array
   4 - output table with element number ; element value pairs
*/
#include <stdio.h>
#define SIZE 5// define symbolic constant using the preprocessor directive

int main(void)
{
   // 1 - Declare & initialise array to zeros
   int numbers[SIZE]={0};
   int sum = 0;
   size_t count;
   
   // 2 - read 10 integers from the user into the array
   for(count = 0; count < SIZE; count++)
   {
      printf("Enter number %Zu ", count+1);
      scanf("%d", &numbers[count]);
   }
      
   // 3 - sum the numbers in the array
   for(count = 0; count < SIZE; count++)
   {
      sum += numbers[count];
   }
      
   //4 - output table with element number ; element value pairs
   printf("Element Number\tElement Value\n");
   for(count = 0; count < SIZE; count++)
   {
      printf("%Zu\t\t%d\n",count,numbers[count]);
   }
   printf("The sum is %d\n",sum);
   
}








