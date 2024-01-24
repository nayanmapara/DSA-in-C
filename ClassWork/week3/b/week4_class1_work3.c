// Write a program that will use a function to increase a user supplied input 
// by 10%
#include <stdio.h>

// function prototype for a pass-by-value
int increaseByValue(int value);

int main(void)
{
   int value, answer=0;
   printf("Enter Value to be Increased: ");
   scanf("%d", &value);

   // add code for function call here 
   answer = increaseByValue(value);

   printf("The value is %d and The answer is %d: \n", value, answer);
}

// Implement function definition here
int increaseByValue(int value)
{
   return value * 1.10;
}

