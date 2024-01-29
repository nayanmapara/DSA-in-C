// Fig. 8.35: fig08_35.c
// Using function strlen
#include <stdio.h>
#include <string.h>

int main( void )
{
   // initialize 3 char pointers
   const char *string1 = "abcdefghijklmnopqrstuvwxyz";
   const char *string2 = "four";
   const char *string3 = "Boston";
   
   printf("%s\"%s\"%s%zu\n%s\"%s\"%s%zu\n%s\"%s\"%s%zu\n",
     "The length of ", string1, " is ", strlen( string1 ),
     "The length of ", string2, " is ", strlen( string2 ),
     "The length of ", string3, " is ", strlen( string3 ) );
} // end main


