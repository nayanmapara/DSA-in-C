#include <stdio.h>
#include <stdlib.h>

// Operating and maintaining a queue

struct queueNode{// Structure definition
   int data;// define data as an integer            
   struct queueNode *nextPtr;// queueNode pointer
};   // end structure queueNode                     

// Use typedef to rename types
typedef struct queueNode QueueNode;
typedef struct queueNode *QueueNodePtr;

// function prototypes
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value);
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
int isEmpty(QueueNodePtr headPtr);
void printQueue(QueueNodePtr headPtr);
void instructions(void);


/*Function Definitions*/

// insert a node in at queue tail
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value)
{ 
   // Declare pointer to store address of new QueueNode
   QueueNodePtr newPtr;
   
   // Create memory for new QueueNode
   newPtr = malloc(sizeof(QueueNode));
   
   if (newPtr != NULL){// if is space available 
      newPtr->data = value;// load data into new node
      newPtr->nextPtr = NULL;
      if (*headPtr == NULL){// if queue is empty, insert node at head
         *headPtr = newPtr;// add code to insert node at the head
      } else {// otherwise insert at the tail
         (*tailPtr)->nextPtr = newPtr;// add code to insert node at the tail
      }
      *tailPtr = newPtr;// update tailPtr ... this is always done 
      
   } else {
      puts("Memory issues... Node not created.");
   }
}


// remove node from queue head
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{ 
   QueueNodePtr tempPtr;// Declare temporary node pointer to isolate node to be deleted
   tempPtr = *headPtr;// store headPtr into tempPtr              
   printf("%d being dequeued\n", tempPtr->data);// inform user  or return value; 
   *headPtr = (*headPtr)->nextPtr;// update headPtr
   if (*headPtr == NULL) {// if queue is empty, update tailPtr
      *tailPtr = NULL;// add code to update tailPtr
   }
   // de-allocate memory from tempPtr
   free(tempPtr);
}


// return 1 if the queue is empty, 0 otherwise
int isEmpty(QueueNodePtr headPtr)
{ 
   //return queue is empty if headPtr == NULL
   if (headPtr == NULL) {
      return 1;
   } else {
      return 0;
   }
} 


// print the queue
void printQueue( QueueNodePtr headPtr )
{ 
   // set currentPtr to head of queue
   QueueNodePtr currentPtr = headPtr;
   // if queue is empty
   if ( currentPtr == NULL ) {
      puts( "\n Queue is empty.\n" );
   } // end if
   else { 
      puts( "The queue is:" );

      // while not end of queue
      while ( currentPtr != NULL ) { 

         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;
      } // end while
 
      puts( "NULL\n" );
   } // end else
} // end function printQueue

// display program instructions to user
void instructions( void )
{ 
   printf ( "Enter your choice:\n"
           "   1 to add an item to the queue\n"
           "   2 to remove an item from the queue\n"
           "   3 to end\n" );
} // end function instructions



