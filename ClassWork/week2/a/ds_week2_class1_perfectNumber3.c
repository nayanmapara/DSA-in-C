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
	
	Part 3 (Homework):
	Update your program to use a method to implement the perfect-number
	functionality.        
*/

#include<stdio.h>
void perfectNumber(int number); // function declaration

int main()
{
   int sumOfFactors;
   unsigned int count, number;

   // determine all perfect numbers less than 1000 
   // Use a method  
   for(number = 1; number < 1000000; number++)
   { 
      perfectNumber(number); // function call/usage
   }//end outer for loop 

}

// function definition
void perfectNumber(int number) 
{
     int sumOfFactors = 0, factor;
     for(factor = 1; factor <= number/2; factor++)
     {
      if (number % factor == 0)
      {
        //printf("%d is a factor\n", factor);
        sumOfFactors += factor;
      }
     }// end inner for loop
   
     // determine if number is perfect (or not)
     if (sumOfFactors == number)
       printf("%d [is] a Perfect Number\n", number);


}
 











