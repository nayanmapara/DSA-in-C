// The relationship between pointers and arrays

#include <stdio.h>

int main (void)
{
   size_t i;
   int numbers[5]={5,10,15,20,25};
   int *nPtr;
   
   //Setup Pointer to Point to the Array
   nPtr = numbers;

   
   // display values using array subscripting
   puts("Displaying values using Array Subscripting: \n");
   for(i=0; i<5; i++)
   {
      // Add code here
      printf("%d ", numbers[i]);
   }   
   puts("");
   

   // display values using Pointer subscripting
   puts("Displaying values using Pointer Subscripting: \n");
   for(i=0; i<5; i++)
   {
      // Add code here
      printf("%d ", nPtr[i]);
   }   
   puts("");
   

   // display values using Pointer offset 
   // (with array name as the pointer)
   
   puts("Print with Pointer Offset (using array name) : \n");
   for(i=0; i<5; i++)
   {
      // Add code here
      printf("%d ", *(numbers+i));
   }   
   puts("");
   

   // Display values using Pointer offset 
   // (using the pointer)
      
   puts("Print with Pointer Offset using the pointer : \n");
   for(i=0; i<5; i++)
   {
      // Add code here
      printf("%d ", *(nPtr+i));
   }   
   puts("");
   

}  
