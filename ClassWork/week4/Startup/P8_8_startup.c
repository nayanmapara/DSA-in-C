// Exercise 8.8 Solution
#include <stdio.h>
#include <stdlib.h>

int main( void )
{ 
   char stringValue[ 80 ]; // string input by user
   double sum = 0.0; // sum of all four values
   int i; // loop counter
   
   // loop 4 times
   for ( i = 1; i <= 4; ++i ) { 
      printf( "%s", "Enter a floating point string: " );
      // Using fgets to get string
      fgets( stringValue, 80, stdin);

      // use strtod() to convert stringValue to a floating-point value
      // Accumulate total
      sum += strtod( stringValue, NULL);
   } // end for
   
   printf( "\nThe total of the values is %f\n", sum );
} // end main


 
