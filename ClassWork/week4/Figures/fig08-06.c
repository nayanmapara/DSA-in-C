// Fig. 8.6: fig08_06.c
// Using function strtod  ... you could also try strtof() and strtold()
#include <stdio.h>
#include <stdlib.h>
int main( void )
{ 
   // initialize string pointer
   const char *string = "51.2% are admitted"; // initialize string

   // float fnum; // variable to hold converted sequence
   // double dnum; // variable to hold converted sequence
   long double ldnum; // variable to hold converted sequence
   char *stringPtr = NULL; // create char pointer
   
   // fnum = strtof( string, &stringPtr );   //  string to float
   // dnum = strtod( string, &stringPtr );   // string to double
   ldnum = strtold( string, NULL);  // string to long double
   
   printf( "The string \"%s\" is converted to the\n", string );
   // printf( "     Float  value %.2f \n", fnum);
   // printf( "     Double value %.2f \n", dnum);
   printf( "Long Double value %.2Lf \n",ldnum);
  
   // printf( "The Remainder of the String is... %s \n", stringPtr);
} // end main


 

