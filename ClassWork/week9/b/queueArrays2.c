#include "queueArrays.h"

int main(void)
{
  // define Queue Pointer & Initialize Queue
  QueueTypePtr qPtr = initQueue();
  int number; 
  printf("Enter an Integer At most MAXINT-1:");
  scanf("%d",&number);
  while(number > 0)
  {
     enqueue(qPtr, number % 10);
     number = number / 10;
  }
  puts("The values in the queue are: ");
  while(!isEmpty(qPtr))
  {
    printf("%d -> ",dequeue(qPtr));// and print values
  }
  puts("END");
  free(qPtr);//de-allocate queue memory
}