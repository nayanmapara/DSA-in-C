// Queue routine definitions (Using array implementation) header file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxQ 10   // Set Predefined Constant for Queue size

// Define queue structure
typedef struct queueType
{
   int head;
   int tail;
   int QA[MaxQ];
} QueueType, *QueueTypePtr;

   
// Function Prototypes
QueueTypePtr initQueue(); 		        /*Initialise queue       */
bool isEmpty(QueueTypePtr qPtr);                     /*Check if queue is empty*/
void enqueue(QueueTypePtr qPtr, int value);              	/*Add to queue           */
int dequeue(QueueTypePtr qPtr);	                /*Remove from Queue      */
void front(QueueTypePtr qPtr);
void back(QueueTypePtr qPtr);

// Function Definitions
QueueTypePtr initQueue() /*Initialise queue       */
{
   QueueTypePtr qPtr;                              // declare Q pointer
   qPtr = (QueueTypePtr)malloc(sizeof(QueueType)); // create memory for queue
   if (qPtr != NULL)
   {
      qPtr->head = 0; // initialise Q indexes head , tail
      qPtr->tail = 0;
   }
   else
   {
      puts("Memory issues... Not created..."); // return pointer to Q
   }
}

bool isEmpty(QueueTypePtr qPtr) /*Check if queue is empty*/
{
   // return true is head == tail;
   return (qPtr->head == qPtr->tail);
}

void enqueue(QueueTypePtr qPtr, int value) /*Add to queue           */
{
   if (qPtr->tail == MaxQ - 1) // check if tail is MaxQ before incrementing tail
   {
      qPtr->tail = 0; // set to zero since it is a circular array implementation
   }
   else
   {
      ++(qPtr->tail); // otherwise do a normal increment
   }

   if (qPtr->head == qPtr->tail) // check if queue is full after the increment
   {
      puts("Queue is full... ");
      if (qPtr->tail == 0) // condition to undoing the circular increment since queue is full
      {
         qPtr->tail = MaxQ - 1; // undo circular increment
      }
      else
      {
         --(qPtr->tail); // otherwise undo regular increment
      }
      return;
   }
   qPtr->QA[qPtr->tail] = value; // store value into Q array at tail index
}

int dequeue(QueueTypePtr qPtr) /*Remove from Queue      */
{
   // if (isEmpty(qPtr)) // check if queue is empty
   // {
   //    puts("Queue is empty... nothing to dequeue");// inform user "Queue is empty... nothing to dequeue");
   //    return EmptyValue;
   // } //Also my fault, we're doing the test for null before we usee dequeue...
   if (qPtr->head == MaxQ-1) // condition increment head index for circular array
   {
      qPtr->head = 0;// set index to zero
   }
   else
   {
      ++(qPtr->head);// otherwise do a regular increment
   }
   return qPtr->QA[qPtr->head];// return dequeued value
}

void front(QueueTypePtr qPtr)
{
   printf("Front of Queue: %d\n", qPtr->QA[qPtr->head]);
}

void back(QueueTypePtr qPtr)
{
   printf("Back of Queue: %d\n", qPtr->QA[qPtr->tail]);
}