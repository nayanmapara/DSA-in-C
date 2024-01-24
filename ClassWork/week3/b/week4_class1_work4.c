// Write a program that will use a function to increase a user supplied input 
// by 10%
#include <stdio.h>

// function prototype for a pass-by-reference / address / pointer
void increaseByPointer(int *valuePtr);

int main(void)
{
   int value;
   printf("Enter Value to be Increased: ");
   scanf("%d", &value);

   // add code for function call here 
   increaseByPointer(&value);

   printf("The value is: %d\n", value);
}

// Implement function definition here
void increaseByPointer(int *valuePtr)
{
   *valuePtr = *valuePtr * 1.10;
}