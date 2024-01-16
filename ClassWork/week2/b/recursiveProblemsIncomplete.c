// Use recursion to solve and test the following problems

#include <stdio.h>


unsigned long int factorial (unsigned long int number);
int power (int base, int exp);
int multiply(int num1, int num2);
int divide (int numerator, int denominator);
int findSumOfDigits(int n);
int countDigits(int n);
int sumNatural(int n);


int main()
{
    // unsigned long int result = 0; // For fractorial
    int result = 0; 
    
    // result = factorial(20);
    // result = power(4,3);
    // result = multiply(4,3);
    // result = divide(41,3);
    result = findSumOfDigits(583);
    
    // printf("The Result is %ld \n", result); // For factorial 
    printf("The Result is %d \n", result); 
    

}

// unsigned long int factorial (unsigned long int number)
// {
//   if ( number <= 1)
//     return 1;
//   else
//     return number * factorial(number-1); 
// }

int power (int base, int exp)
{
  if (exp == 0)
    return 1;
  else if (exp == 1)
      return base;
    else
       return base * power(base,exp-1);
}

// Multiply by using a series of additions
int multiply(int num1, int num2)
{
  if (num2 == 0)
     return 0;
  else
     return  num1 + multiply(num1,num2-1);
}

// Divide by using a series of subtractions
int divide (int numerator, int denominator)
{
   if(numerator < denominator)
     return 0;
   else
     return 1 + divide(numerator-denominator,denominator);
}

int findSumOfDigits(int n)
{
  int rem; 
  if(n == 0) 
     return 0;  
  else 
     return n%10 + findSumOfDigits(n/10);
} 



