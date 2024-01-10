/*
   Write a program that accepts 10 numbers from the user, sums the  
   numbers and outputs the sum.
*/
#include <stdio.h>
int main(void)
{
  // declare number, sum
  int number = 0;
  int sum = 0;
  
  // declare counter, ensure it is not signed
  unsigned int counter = 1;
  while(counter <= 10)// counter loop 10 times)       
  {
    printf("Enter the number: ");
    // read number
    scanf("%d", &number);

    // accummulate sum of numbers
    sum = sum + number;
    
    // update counter
    counter++;
  }
  // output the sum
  printf("Sum: %d\n", sum);
}
