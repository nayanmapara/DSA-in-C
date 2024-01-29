// Exercise 8.7 Solution
#include <stdio.h>
#include <stdlib.h>

int main( void )
{ 
   char stringValue[ 80 ]; // integer string input by user
   int sum = 0; // result of four integers
   int i; // loop counter
   
   //1: loop 4 times, read string and use strtol() to process input 
   for ( i = 1; i <= 4; ++i ) { 
      printf( "%s", "Enter an integer string: " );
      // read string here
      fgets( stringValue, 80, stdin);

      // converts stringValue to integer and accumulate sum
      sum += (int) strtol(stringValue, NULL, 0);
      
   } // end for
   
   printf( "\nThe total of the values is %d\n", sum );
} // end main



 