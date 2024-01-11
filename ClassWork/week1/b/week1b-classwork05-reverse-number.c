// Program that accepts a 4 digit number and splits it into its separate digits 
// and then reverses the number

#include <stdio.h>
int main (void)
{
   int digit1=0, digit2=0, digit3=0, digit4=0, number=0, revNum=0;
   
   printf("Enter a 4-digit Number: ");
   scanf("%d",&number);
  
   // splitting the number to get digit 4
   digit4 = number % 10;
   // updating the number to continue splitting
   number = number / 10;

   // splitting the number to get digit 3
   digit3 = number % 10;
   // updating the number to continue splitting
   number = number / 10;

   // splitting the number to get digit 2
   digit2 = number % 10;
   // updating the number to continue splitting
   number = number / 10;

   // splitting the number to get digit 1
   digit1 = number % 10;
   // end splitting
   
   // add and multiply to reverse number
   revNum = digit4*1000 + digit3*100 + digit2*10 + digit1;
   
   // output reverse-number
   printf("%d\n", revNum);
}