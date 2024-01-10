/*
A Hailstone series is defined as follows: start with any integer value greater than 0, say x. If x is even, then the next value in the series is x/2; if x is odd, then the next value in the series is 3x + 1. Now apply the same rules to create the next value in the series, and so on. The name Hailstone comes from the property that the values in such a series alternate between going up and down (up for odd values and down for even values.) 

For instance, here is the Hailstone series generated from starting value 17:
17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1

Note that if a Hailstone series ever reaches the value 1, then the next value generated is 4, the next is 2, and the next is 1 again. Thus, when a Hailstone series reaches 1, then it has converged in the sense that the rest of the series is 4, 2, 1, 4, 2, 1, ... . 

For this assignment, you will write a program that allows users to enter a starting value from which the program computes and outputs the corresponding Hailstone series (stopping with 1 if it ever reaches 1). 
*/

#include <stdio.h>
int main()
{
  int number;
  printf("Enter Starting Value for Hailstone series: ");
  scanf("%d", &number);
  
  while(//test for ground state)
  {
     // display current number
     if (//ground state reached)
     {
       // end the sequence
     }
     else if (// test if number is even)
     { 
       // add code to shrink number down ; 
     }
     else
     { 
       // add code to grow number up ;
     }
  }
  
}



















