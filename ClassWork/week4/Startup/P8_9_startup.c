// Exercise 8.9 Solution
#include <stdio.h>
#include <string.h>

int main( void )
{ 
   char string1[ 20 ]; // first string input by user
   char string2[ 20 ]; // second string input by user
   int result; // result of comparing two strings

   printf( "%s", "Enter two strings: \n" );
   // read two strings
   printf("Enter string 1: ");
   fgets( string1, 20, stdin);
   printf("Enter string 2: ");
   fgets( string2, 20, stdin);
   
   result = strcmp( string1, string2); // use strcmp() to decide the if the strings are equal 
  
   // display appropriate message for result
   if ( result > 0 ) {
      printf( "\"%s\" is greater than \"%s\"\n", string1, string2 );
   } // end if
   else if ( 0 == result ) {
      printf( "\"%s\" is equal to \"%s\"\n", string1, string2 );
   } // end else if
   else {
      printf( "\"%s\" is less than \"%s\"\n", string1, string2 );
   } // end else
} // end main



 
