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

// Queue specific function prototypes
// function prototypes
void enqueue(CarPtr *headPtr, CarPtr *tailPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price);
void dequeue(CarPtr *headPtr, CarPtr *tailPtr);
int isQueueEmpty(CarPtr headPtr);
void printQueue(CarPtr headPtr);
void instructions(void);
void frontOfQueue(CarPtr headPtr);
void backOfQueue(CarPtr tailPtr);

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


int isEmpty(CarPtr topPtr)
{
	// return true if topPtr is NULL of False otherwise;
	return (topPtr == NULL);
}


// Queue functions
// insert a node in at queue tail
void enqueue(CarPtr *headPtr, CarPtr *tailPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price)
{
   CarPtr newPtr; // Declare pointer to store address of new QueueNode

   newPtr = (CarPtr) malloc(sizeof(Car)); // Create memory for new QueueNode Dunno why this looks like an error, it is not. It works.

   if (newPtr != NULL) // if is space available
   {
      	// Recycled code from add car
		strcpy(newPtr->carVIN, VIN);
		strcpy(newPtr->carMake, make);
		strcpy(newPtr->carModel, model);
		newPtr->carBodyStyle = bodyStyle;
		newPtr->carYear = year;
		newPtr->carPrice = price;

      newPtr->nextPtr = NULL; // load data into new node
      if (*headPtr == NULL)
      {                     // if queue is empty, insert node at head
         *headPtr = newPtr; // add code to insert node at the head
      }
      else
      { // otherwise insert at the tail
        (*tailPtr)->nextPtr = newPtr; // add code to insert node at the tail
      }
      *tailPtr = newPtr;// update tailPtr ... this is always done
   }
   else
   {
      puts("Memory issues... Node not created...");
   }
}

// remove node from queue head
void dequeue(CarPtr *headPtr, CarPtr *tailPtr)
{
   CarPtr tempPtr;// Declare temporary node pointer to isolate node to be deleted
   tempPtr = *headPtr;// store headPtr into tempPtr
   //printf("Car with VIN %s is being dequeued\n", tempPtr->carVIN);// inform user  or return value;
   printf("Car %s\t%s\t\t%s\t\t%c\t\t%u\t\t$%.2f\t\n is being dequeued", tempPtr->carVIN, tempPtr->carMake, tempPtr->carModel, tempPtr->carBodyStyle, tempPtr->carYear, tempPtr->carPrice);
   *headPtr = (*headPtr)->nextPtr;// update headPtr
   if(*headPtr == NULL){// if queue is empty, update tailPtr
      *tailPtr = NULL;// add code to update tailPtr
   }
   free(tempPtr);// de-allocate memory from tempPtr
}

// return 1 if the queue is empty, 0 otherwise
int isQueueEmpty(CarPtr headPtr)
{
   return (headPtr == NULL);// return queue is empty if headPtr == NULL
   //{
   //   return 1;
   //}
   //else
  // {
   //   return 0;
   //}
}

// print the queue
void printQueue(CarPtr headPtr)
{
   CarPtr currentPtr = headPtr;// set currentPtr to head of queue
   // if queue is empty
   if (currentPtr == NULL)
   {
      puts("\n Queue is empty.\n");
   } // end if
   else
   {
      puts("The queue is:");

      // while not end of queue
      while (currentPtr != NULL)
      {

         //printf("%s --> ", currentPtr->carVIN);
		 printf("%s\t%s\t\t%s\t\t%c\t\t%u\t\t$%.2f\t\n", currentPtr->carVIN, currentPtr->carMake, currentPtr->carModel, currentPtr->carBodyStyle, currentPtr->carYear, currentPtr->carPrice);
         currentPtr = currentPtr->nextPtr;
      } // end while

      //puts("NULL\n");
   } // end else
} // end function printQueue

void frontOfQueue(CarPtr headPtr){
   printf("The data at the front of the queue is: %s\t%s\t\t%s\t\t%c\t\t%u\t\t$%.2f\t\n", headPtr->carVIN, headPtr->carMake, headPtr->carModel, headPtr->carBodyStyle, headPtr->carYear, headPtr->carPrice);
}

void backOfQueue(CarPtr tailPtr){
   printf("The data at the back of the queue is: %s\t%s\t\t%s\t\t%c\t\t%u\t\t$%.2f\t\n", tailPtr->carVIN, tailPtr->carMake, tailPtr->carModel, tailPtr->carBodyStyle, tailPtr->carYear, tailPtr->carPrice);
}

// display program instructions to user
void instructions(void)
{
   printf("Enter your choice:\n"
          "   1 Check car in front of queue\n"
          "   2 Check car in back of queue\n"
		  "   3 Add a car to the queue\n"
          "   4 Remove a car from the queue\n"
          "   5 Print Inventory in Queue\n"
          "   6 End program\nSelection: ");
} // end function instructions
