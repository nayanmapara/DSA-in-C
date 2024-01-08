//Program to compute the diameter, area, circumference of a circle

#include <stdio.h>

int main (void)
{
   /* define data container to store floating point value radius*/
   float radius = 0.0;

   /* define read-only data container (constant) value PI with 3.14159 */
   const float PI = 3.14159;     

   /* read radius from the keyboard */
     printf("Enter radius: "); // prompt user 
     scanf("%f", &radius); // get keyboard input

   /* compute and output diameter, circumference and area */
   printf("The area is: %.2f\n",PI * radius * radius);
   printf("The circumference is: %.2f\n", 2 * PI * radius);
   printf("The diameter is: %.2f\n", 2 * radius);
} 
