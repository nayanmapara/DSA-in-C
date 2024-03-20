#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define car with paramater types
struct car
{
	struct car *leftPtr;
	char carVIN[18];
	char carMake[30];
	char carModel[30];
	char carBodyStyle;
	unsigned int carYear;
	float carPrice;
    struct car *rightPtr;

};

typedef struct car Car;
typedef struct car *CarPtr;

// Define old function prototypes
bool uniqueVIN(CarPtr startPtr, char VIN[17]);

// Function prototypes
void insertNode(CarPtr *treePtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price);
void insertNodeWithDuplicates(CarPtr *treePtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price);
void preOrder(CarPtr treePtr);
void inOrder(CarPtr treePtr);
void inReverseOrder(CarPtr treePtr);
void postOrder(CarPtr treePtr);

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
		// currentPtr = currentPtr->nextPtr;
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

void insertNode(CarPtr *treePtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price)
{
    if (*treePtr == NULL) // Node can be inserted as a leaf node
    {
        *treePtr = (CarPtr) malloc(sizeof(Car));

        if (*treePtr != NULL)
        {
            (*treePtr)->leftPtr = NULL;
            strcpy((*treePtr)->carVIN, VIN);
            strcpy((*treePtr)->carMake, make);
            strcpy((*treePtr)->carModel, model);
            (*treePtr)->carBodyStyle = bodyStyle;
            (*treePtr)->carYear = year;
            (*treePtr)->carPrice = price;
            (*treePtr)->rightPtr = NULL;

        } else {
            puts("Memory issues... Node not created.");
        }

        return;

    } else { // otherwise, continue for apporiate place to insert by going left/right
        if (strcmp(VIN, (*treePtr)->carVIN) < 0)
        {
            //go left
            insertNode(&((*treePtr)->leftPtr), VIN, make, model, bodyStyle, year, price);

        } else if (strcmp(VIN, (*treePtr)->carVIN) > 0)
        {
            //go right
            insertNode(&((*treePtr)->rightPtr), VIN, make, model, bodyStyle, year, price);

        } else {
            //duplicate elimination 
            printf("%s", "-duplicate-not-inserted");
        }
        }
}

void insertNodeWithDuplicates(CarPtr *treePtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price)
{
    if (*treePtr == NULL) // Node can be inserted as a leaf node
    {
        *treePtr = (CarPtr) malloc(sizeof(Car));
        if (*treePtr != NULL)
        {
            (*treePtr)->leftPtr = NULL;
            strcpy((*treePtr)->carVIN, VIN);
            strcpy((*treePtr)->carMake, make);
            strcpy((*treePtr)->carModel, model);
            (*treePtr)->carBodyStyle = bodyStyle;
            (*treePtr)->carYear = year;
            (*treePtr)->carPrice = price;
            (*treePtr)->rightPtr = NULL;

        } else {
            puts("Memory issues... Node not created.");
        }

        return;

    } else { // otherwise, continue for apporiate place to insert by going left/right
    if (strcmp(VIN, (*treePtr)->carVIN) <= 0)
    {
        //go left
        insertNodeWithDuplicates(&((*treePtr)->leftPtr), VIN, make, model, bodyStyle, year, price);

    } else
    {
        //go right
        insertNodeWithDuplicates(&((*treePtr)->rightPtr), VIN, make, model, bodyStyle, year, price);
    }
    }
}

void preOrder(CarPtr treePtr)
{
    if (treePtr != NULL)
    {
        // printf("%d ", treePtr->data);
        printf("%s\t%s\t%s\t%c\t%u\t%.2f\n", treePtr->carVIN, treePtr->carMake, treePtr->carModel, treePtr->carBodyStyle, treePtr->carYear, treePtr->carPrice);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void inOrder(CarPtr treePtr)
{
    if (treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        // printf("%d ", treePtr->data);
        printf("%s\t%s\t%s\t%c\t%u\t%.2f\n", treePtr->carVIN, treePtr->carMake, treePtr->carModel, treePtr->carBodyStyle, treePtr->carYear, treePtr->carPrice);
        inOrder(treePtr->rightPtr);
    }
}

void inReverseOrder(CarPtr treePtr)
{
    if (treePtr != NULL)
    {
        inReverseOrder(treePtr->rightPtr);
        // printf("%d ", treePtr->data);
        printf("%s\t%s\t%s\t%c\t%u\t%.2f\n", treePtr->carVIN, treePtr->carMake, treePtr->carModel, treePtr->carBodyStyle, treePtr->carYear, treePtr->carPrice);
        inReverseOrder(treePtr->leftPtr);
    }
}

void postOrder(CarPtr treePtr)
{
    if (treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        // printf("%d ", treePtr->data);
        printf("%s\t%s\t%s\t%c\t%u\t%.2f\n", treePtr->carVIN, treePtr->carMake, treePtr->carModel, treePtr->carBodyStyle, treePtr->carYear, treePtr->carPrice);
    }
}