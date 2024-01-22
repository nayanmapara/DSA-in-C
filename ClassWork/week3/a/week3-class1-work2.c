// program to demonstrate array addressing
#include <stdio.h>
#define SIZE 10

int main()
{
  int numbers[SIZE]={0};
  
  // accessing the address of the array, option-1
  printf("Option 1: %p\n",numbers);
  
  // accessing the address of the array, option-2
  printf("Option 2: %p\n", &numbers);

  // accessing the address of the array, option-3
  printf("Option 3: %p\n", &numbers[0]);
  
}
