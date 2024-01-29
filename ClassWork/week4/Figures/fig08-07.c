// Fig. 8.7: fig08_07.c
// Using function strtol
#include <stdio.h>
#include <stdlib.h>

int main( void )
{                  
   const char *string = "1234567abc"; // initialize string pointer
   
   //char *remainderPtr=NULL; // create char pointer
   //int x; // variable to hold converted sequence
   long int y;
   //unsigned long int w;
   //unsigned int z;
   
   //x = (int)strtol( string,NULL,0 );
   y = strtol( string,NULL, 0 );
   //w = strtoul( string, NULL, 0 );
   //z = (int)strtoul( string, NULL, 0 );  

   //printf( "Integer value %d \n",x);
   //printf( "Long int value %ld \n",y);
   //printf( "Unsigned Long int value %lu \n",w);
   //printf( "Unsigned int value %u \n",z);

   //printf( "The Remainder of the String is %s \n", remainderPtr);
} // end main



