// Name: Nayan

#include <stdio.h>

int main (void)
{
   int hours;
   float hourRate, salary;

   printf("Enter #  of hours  worked (-1 to end): ");
   scanf("%d", &hours);

   while (hours != -1)
   {

    printf("Enter hourly rate of the worker ($00.00): ");
    scanf("%f", &hourRate);

    if (hours <= 40)
    {
        salary = hours * hourRate;
    }
    else
    {
        salary = 40 * hourRate + (hours - 40) * hourRate * 1.5;
    }

    printf("Salary is $%.2f\n\n", salary);

    printf("Enter #  of hours  worked (-1 to end): ");
    scanf("%d", &hours);
   }

}
