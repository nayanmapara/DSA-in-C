/*
   Write a program that accepts a series of numbers from the user, 
   totals and averages the numbers and then outputs the 
   total and average.
*/
#include <stdio.h>
int main(void)
{
  int number=0, total = 0, average = 0;
  unsigned int counter = 0;

  printf("Enter Number... (-1 to quit): ");
  scanf("%d", &number);
  
  while(number != -1) //condition to continue indefinitely  // use a sentinel loop
  {
     //accumulate total for numbers entered;
     total += number;

     //count each number 
     counter++;

     //continue to get user input 
     printf("Enter Number... (-1 to quit): ");
     scanf("%d", &number);
      
  }
  // compute average
  if ( counter == 0)
  {
   printf("No numbers were processed\n");
  } else
  {
   average = total / counter;
  }
  // Output total, average, counter
  printf("Total %d\tAverage %d\t Count is %u\n",total,average,counter);
  
}



