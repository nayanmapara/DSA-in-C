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

// Stack specific function prototypes
CarPtr pushCar(CarPtr topPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price);
CarPtr popCar(CarPtr topPtr);
int isEmpty(CarPtr topPtr); // I'd like to make this a bool in the future
void topOfCarStack(CarPtr topPtr);
void bottomOfCarStack(CarPtr topPtr);
void printCarStack(CarPtr currentPtr);
void stackMenu(void);

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

// New stack functions go here
CarPtr pushCar(CarPtr topPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price)
{
	CarPtr newPtr; // Initialise pointer for new StackNode

	newPtr = (CarPtr)malloc(sizeof(Car)); // Create memory for new StackNode

	// Push new StackNode onto top-of-stack
	if (newPtr != NULL)
	{
		// add code to push
		// Recycled code from add car
		strcpy(newPtr->carVIN, VIN);
		strcpy(newPtr->carMake, make);
		strcpy(newPtr->carModel, model);
		newPtr->carBodyStyle = bodyStyle;
		newPtr->carYear = year;
		newPtr->carPrice = price;

		// Pushes car down the stack
		newPtr->nextPtr = topPtr;
		topPtr = newPtr;
	}
	else
	{
		printf("%s not inserted. No memory available.\n", VIN);
	}
	return topPtr;
	// return pointer to top-of-stack;
}

CarPtr popCar(CarPtr topPtr)
{
	// Initialise temporary pointer to hold address of StackNode to pop
	CarPtr tempPtr;
	/* add code to pop StackNode from the top-of-stack */
	// isolate StackNode to be deleted / popped
	tempPtr = topPtr;
	// inform user of Node to be popped
	printf("Car with VIN %s is being removed.\n", topPtr->carVIN);
	// update topPtr
	topPtr = topPtr->nextPtr;
	// deallocate memory
	free(tempPtr);
	// return pointer to top-of-stack
	return topPtr;
}

// To-do: Improve this to print better
void printCarStack(CarPtr topPtr)
{
	CarPtr currentPtr = topPtr;
	if (currentPtr == NULL /*stack is empty*/)
	{
		// inform user "The stack is empty"
		puts("The stack is empty.\n");
	}
	else
	{
		printf("The stack is:\n");
		printf("\tVIN\t\tMake\t\tModel\t\tType\tYear\tPrice\t\n");
		while (currentPtr != NULL /*not at the end of stack*/)
		{
			// print current node
			// printf("%s --> ", currentPtr->carVIN);

			// printf("%s  %s  %s  %c  %u  $%.2f  -->  ", currentPtr->carVIN, currentPtr->carMake, currentPtr->carModel, currentPtr->carBodyStyle, currentPtr->carYear, currentPtr->carPrice);
			printf("--> %s\t\t%s\t\t%s\t\t%c\t%u\t$%.2f\t\n", currentPtr->carVIN, currentPtr->carMake, currentPtr->carModel, currentPtr->carBodyStyle, currentPtr->carYear, currentPtr->carPrice);

			// move onto the next node
			currentPtr = currentPtr->nextPtr;
		}
		printf("\t\t\t----- End of the stack -----\n");
	}
}

int isEmpty(CarPtr topPtr)
{
	// return true if topPtr is NULL of False otherwise;
	return (topPtr == NULL);
}

void topOfCarStack(CarPtr topPtr)
{

	// display value at the top-of-stack
	// printf("The value at the top of the stack is %s\n\n", topPtr->carVIN);
	printf("The top most car is: %s  %s  %s  %c  %u  $%.2f\n", topPtr->carVIN, topPtr->carMake, topPtr->carModel, topPtr->carBodyStyle, topPtr->carYear, topPtr->carPrice);
}

void bottomOfCarStack(CarPtr topPtr)
{
	CarPtr currentPtr = topPtr;
	if (currentPtr == NULL /*stack is empty*/)
	{
		// inform user "The stack is empty"
		puts("The stack is empty.");
	}
	while (currentPtr != NULL /*not at the end of stack*/)
	{

		if (currentPtr->nextPtr == NULL)
			printf("The bottom most car is: %s  %s  %s  %c  %u  $%.2f\n", currentPtr->carVIN, currentPtr->carMake, currentPtr->carModel, currentPtr->carBodyStyle, currentPtr->carYear, currentPtr->carPrice);
		// move onto the next node
		currentPtr = currentPtr->nextPtr;
	}
}

void stackMenu(void)
{
	printf("Enter a number from below:\n(1) Top most car \n(2) Bottom most car\n(3) Add a car\n(4) Remove a car\n(5) Print all the cars\n(6) To exit the app\nChoice: ");
}
