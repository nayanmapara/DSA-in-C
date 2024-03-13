// Queue routine definitions (Using array implementation) header file
#include <stdio.h>
#include <stdlib.h>

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
int isEmpty(QueueTypePtr qPtr);                     /*Check if queue is empty*/
void enqueue(QueueTypePtr qPtr, int value);              	/*Add to queue           */
int dequeue(QueueTypePtr qPtr);	                /*Remove from Queue      */
void front(QueueTypePtr qPtr);
void back(QueueTypePtr qPtr);

// Function Definitions
QueueTypePtr initQueue() 		        /*Initialise queue       */
{
  QueueTypePtr qPtr;// declare Q pointer
  qPtr = (QueueTypePtr) malloc(sizeof(QueueType));// create memory for queue
  if (qPtr != NULL)// initialise Q indexes head , tail
  {
      qPtr->head = 0;
      qPtr->tail = 0;
  } else {
      puts("Memory issues... Queue not created...");
  }
  // return pointer to Q
  return qPtr;
}


int isEmpty(QueueTypePtr qPtr)                 /*Check if queue is empty*/
{
   // return true is head == tail;
   return (qPtr->head == qPtr->tail);
}

void enqueue(QueueTypePtr qPtr, int value)	/*Add to queue           */
{
   if(qPtr->tail == MaxQ-1)// check if tail is MaxQ before incrementing tail
   {
      // set to zero since it is a circular array implementation
      qPtr->tail = 0;
   }
   else{
      // otherwise do a normal increment
      ++(qPtr->tail);
   }
   return;
   
   if(qPtr->head == qPtr->tail)// check if queue is full after the increment
   {
      puts("Queue is full... "); 
      if(qPtr->tail == 0)// condition to undoing the circular increment since queue is full
      {
         // undo circular increment
         qPtr->tail = MaxQ-1;
      }
      else{
         // otherwise undo regular increment
         --(qPtr->tail);
      }
      return;
   }
   qPtr->QA[qPtr->tail] = value;//store value into Q array at tail index
}


int dequeue(QueueTypePtr qPtr)	                /*Remove from Queue      */
{
   if(qPtr->head == MaxQ-1)// condition increment head index for circular array
   {
      qPtr->head = 0;// set index to zero
   }
   else{
      ++(qPtr->head);// otherwise do a regular increment
   }
   // return dequeued value
   return qPtr->QA[qPtr->head];
}

void front(QueueTypePtr qPtr)
{
   printf("Front of Queue: %d\n", qPtr->QA[qPtr->head]);
}

void back(QueueTypePtr qPtr)
{
   printf("Back of Queue: %d\n", qPtr->QA[qPtr->tail]);
}