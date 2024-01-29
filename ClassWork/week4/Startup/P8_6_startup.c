// Exercise 8.6 Solution
#include <stdio.h>
#include <ctype.h>

int main( void )
{ 
   char s[ 100 ]; // define character array of size 100
   size_t i; // loop counter
     
   // use gets to get text from user
   puts( "Enter a line of text:" );

   //1: Read line of text using fgets
   fgets(s, 100, stdin);

   puts( "\nThe line in uppercase is:" ); 
   
   //2: Use a loop and toupper to convert each character to uppercase and output
   for(i=0; s[i] != '\0'; i++)
   {
      putchar(toupper(s[i]));
      // printf("%c", toupper(s[i]));
   }
   

   puts( "\nThe line in lowercase is:" );
   
   //2: Use a loop and toupper to convert each character to lowercase and output
   for(i=0; s[i] != '\0'; i++)
   {
      putchar(tolower(s[i]));
      // printf("%c", tolower(s[i]));
   }
   

   puts( "" );
} // end main



 