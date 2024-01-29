#include <stdio.h>

int main()
{
   char stringValue[ 80 ]; // string to be input by user
   char ch;                  // char to be input by user
   
   printf( "%s", "Enter a floating point string: " );
   fgets( stringValue, 15, stdin );
   
   printf( "%s", "The Value of the String is: " );
   puts(stringValue);
   
   ch = getchar();
   putchar(ch);
   
   puts("\n");
   
   
   
}
