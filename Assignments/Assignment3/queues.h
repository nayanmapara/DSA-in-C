#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define car with paramater types
struct car
{
	char carVIN[18];
	char carMake[30];
	char carModel[30];
	char carBodyStyle;
	unsigned int carYear;
	float carPrice;
	struct car *nextPtr;
};

typedef struct car Car;
typedef struct car *CarPtr;

// Define old function prototypes
bool uniqueVIN(CarPtr startPtr, char VIN[17]);


// function prototypes
void enqueue(CarPtr *headPtr, CarPtr *tailPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price);
void dequeue(CarPtr *headPtr, CarPtr *tailPtr);
int isEmpty(CarPtr headPtr);
void printQueue(CarPtr headPtr);
void instructions(void);
void frontOfQueue(CarPtr headPtr);
void endOfQueue(CarPtr tailPtr);

/*Function Definitions*/

// insert a node in at queue tail
void enqueue(CarPtr *headPtr, CarPtr *tailPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price)
{ 
   // Declare pointer to store address of new QueueNode
   CarPtr newPtr;
   
   // Create memory for new QueueNode
   newPtr = malloc(sizeof(CarPtr));
   
   if (newPtr != NULL){// if is space available 
      // load data into new node
      strcpy(newPtr->carVIN, VIN);
      strcpy(newPtr->carMake, make);
      strcpy(newPtr->carModel, model);
      newPtr->carBodyStyle = bodyStyle;
      newPtr->carYear = year;
      newPtr->carPrice = price;

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
void dequeue(CarPtr *headPtr, CarPtr *tailPtr)
{ 
   CarPtr tempPtr;// Declare temporary node pointer to isolate node to be deleted
   tempPtr = *headPtr;// store headPtr into tempPtr              
   // inform user  or return value; 
   printf("Car with VIN %s is being dequeued\n", tempPtr->carVIN);

   *headPtr = (*headPtr)->nextPtr;// update headPtr
   if (*headPtr == NULL) {// if queue is empty, update tailPtr
      *tailPtr = NULL;// add code to update tailPtr
   }
   // de-allocate memory from tempPtr
   free(tempPtr);
}


// return 1 if the queue is empty, 0 otherwise
int isEmpty(CarPtr headPtr)
{ 
   //return queue is empty if headPtr == NULL
   if (headPtr == NULL) {
      return 1;
   } else {
      return 0;
   }
} 


// print the queue
void printQueue( CarPtr headPtr )
{ 
   // set currentPtr to head of queue
   CarPtr currentPtr = headPtr;
   // if queue is empty
   if ( currentPtr == NULL ) {
      puts( "\n Queue is empty.\n" );
   } // end if
   else { 
      puts( "The queue is:" );

      // while not end of queue
      while ( currentPtr != NULL ) { 

         // printf( "%d --> ", currentPtr->data );
         printf("--> %s  %s  %s  %c  %u  $%.2f", currentPtr->carVIN, currentPtr->carMake, currentPtr->carModel, currentPtr->carBodyStyle, currentPtr->carYear, currentPtr->carPrice);
         currentPtr = currentPtr->nextPtr;
      } // end while
 
      puts( "--> NULL\n" );
   } // end else
} // end function printQueue

// display program instructions to user
void instructions( void )
{ 
   printf ( "Enter your choice:\n"
           "   1 to add an item to the queue\n"
           "   2 to remove an item from the queue\n"
           "   3 front of queue\n"
           "   4 end of queue\n"
           "   5 print queue\n"
           "   6 to end\n" );
} // end function instructions

void frontOfQueue(CarPtr headPtr)
{
   if (headPtr != NULL)
   {
      // printf("The front of the queue is: %d\n", headPtr->data);
      printf("The front of the queue is: %s  %s  %s  %c  %u  $%.2f\n", headPtr->carVIN, headPtr->carMake, headPtr->carModel, headPtr->carBodyStyle, headPtr->carYear, headPtr->carPrice);
   }
   else
   {
      puts("The queue is empty.");
   }
}

void endOfQueue(CarPtr tailPtr)
{
   if (tailPtr != NULL)
   {
      // printf("The end of the queue is: %d\n", tailPtr->data);
      printf("The end of the queue is: %s  %s  %s  %c  %u  $%.2f\n", tailPtr->carVIN, tailPtr->carMake, tailPtr->carModel, tailPtr->carBodyStyle, tailPtr->carYear, tailPtr->carPrice);
   }
   else
   {
      puts("The queue is empty.");
   }
}

// Determine if a VIN is in use or not
bool uniqueVIN(CarPtr startPtr, char VIN[18])
{
	CarPtr currentPtr = startPtr;
	int position = 0;

	if (startPtr == NULL)
	{
		return true;
	}

	while (currentPtr != NULL && strcmp(currentPtr->carVIN, VIN) != 0)
	{
		currentPtr = currentPtr->nextPtr;
		position++;
	}

	if (currentPtr == NULL)
	{
		return true;
	}
	else
	{
		printf("Car with VIN %s already exists!\n", VIN);
		return false;
	}
}