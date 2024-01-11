// Name: Nayan

// Table of squares and cubes

#include <stdio.h>

int main (void)
{
   int number;
   
   printf("number\tsquare\tcube\n");
   for (int i = 0; i <= 10; i++)
   {
    printf("%d\t%d\t%d\t\n", i, i * i, i * i * i);
   }

}
