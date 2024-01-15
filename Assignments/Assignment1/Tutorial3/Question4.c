// Name: Nayan

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
   int userChoice;
   float hours, hourRate, salary;

   do {
      printf("1: Managers\n");
      printf("2: Hourly Workers\n");
      printf("3: Commission Workers\n");
      printf("4: Pieceworkers\n");
      printf("5: Exit\n");
      printf("Enter your pay code: ");
      scanf("%d",&userChoice);
   
      switch(userChoice)
      {
         case 1: 
                printf("Enter weekly salary: ");
                scanf("%f", &salary);
                printf("Salary is $%.2f\n\n", salary);
                break;

         case 2: 
                printf("Enter #  of hours  worked: ");
                scanf("%f", &hours);
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
                break;

         case 3:
                printf("Enter #  of hours  worked: ");
                scanf("%f", &hours);
                printf("Enter hourly rate of the worker ($00.00): ");
                scanf("%f", &hourRate);
                salary = 250.00 + (5.75 * hours);
                printf("Salary is $%.2f\n\n", salary);
                break;

         case 4: 
                printf("Enter #  of pieces worked with: ");
                int pieces;
                scanf("%d", &pieces);
                printf("Enter wage per piece ($00.00): ");
                float wage;
                scanf("%f", &wage);
                salary = pieces * wage;
                printf("Salary is $%.2f\n\n", salary);
                break;

         case 5: 
                  printf("Exiting program...");
                  exit(0);
                  break; // unreachable

         default: printf("Invalid selection!");
      }

   } while(true);
}