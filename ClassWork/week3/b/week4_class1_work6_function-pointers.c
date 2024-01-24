#include <stdio.h>
//function prototypes
void add( double, double);
double subtract (double, double);

int main()
{
	// declaring & initializing pointers-to-functions
	   
	double num1, num2;

	printf( "Enter 2 numbers (separated by a space: ");
	scanf("%lf%lf", &num1, &num2);
	
        // Using function pointers
}

void add (double num1, double num2)
{
 printf( " number1: %f +  number2: %f  is %f \n",num1, num2, (num1 + num2));
}

double subtract (double num1, double num2)
{
  return num1 - num2;
}



