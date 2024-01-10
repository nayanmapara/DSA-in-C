/* 
 *Program to read two integer numbers from the keyboard
 *compute the sum, difference, quotient, product and remainder
 *and output these results to the console
*/
#include <stdio.h> /* add code for header file */
int main (void)
{
   /* define data containers to store results*/  
   int sum=0, difference=0, quotient=0, product=0, remainder=0;
    
   /* define data containers to store input data*/
   int number1=0, number2=0;
   
   /* read first number from the keyboard */
    // prompt the user
    printf("Enter number1: ");
    // read the number
    scanf("%d", &number1);
   
   /* read second number from the keyboard */
    // prompt the user
    printf("Enter number2: ");
    // read the number
    scanf("%d", &number2);
   
   /* Compute the sum, product, quotient, difference & remainder */
   sum = number1 + number2;
   difference = number1 - number2;
   product = number1 * number2;
   
   
   /* Output the results */
   printf("The sum is %d\n", sum);
   printf("The difference is %d\n", difference);
   printf("The product is %d\n", product);
   printf("The quotient is %d\n", number1 / number2);
   printf("The reminder is %d\n", number1 % number2);
   

}


