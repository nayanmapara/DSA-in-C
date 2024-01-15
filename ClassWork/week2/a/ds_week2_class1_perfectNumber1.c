/* 
	Problem Definition
        Write a program that read an integer and determines if the 
	number is perfect. A perfect number is a number whose factors
	(including 1, but not the number itself) sums to the number. 

	For example:
 	  6 is a perfect number, because its factors (1, 2 ,3 ) sums 
	  to 6.
          but 16 is not perfect, since its factors (1,2,4,8) does not 
	  sum does not sum to 16.
 
        Part 2 (Homework):
	Update your program to output all the perfect numbers less 
	than 1000.        
*/
#include<stdio.h>
int main(void)
{
   int number = 0, sumOfFactors = 0;
   unsigned int count;
   // read number
   printf("Enter an Integer Number ");
   scanf("%d", &number);
   for(count = 1; count <= number/2; count++) // 16... 1 2 3 4 5 6 7 8
   {
      if (number % count == 0)
      {
         sumOfFactors += count;
         printf("%u ", count); 
      }
   }
   if(sumOfFactors == number)
   {
      printf("\nThe number %d is perfect \n", number);
   }
   else{
      printf("\nThe number %d is [not] perfect \n", number);
   }
}
 
 











