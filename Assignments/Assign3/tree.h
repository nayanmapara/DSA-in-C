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
void insertNode(CarPtr *carPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price);
void insertNodeWithDuplicates(CarPtr *treePtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price);
void preOrder(CarPtr carPtr);
void inOrder(CarPtr carPtr);
void inReverseOrder(CarPtr carPtr);
void postOrder(CarPtr carPtr);

// Binary Search Tree Function prototype
CarPtr binaryTreeSearch(CarPtr carPtr, char searchKey[17]);

// Delete search functions
void deleteNode(CarPtr *carPtr, char VIN[17]);
void searchNode(CarPtr *treePtr, char VIN[17], CarPtr *parentPtr, CarPtr *tempNodePtr, int *found);

void insertNode(CarPtr *carPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price)
{
    if (*carPtr == NULL) // Node can be inserted as a leaf node
    {
        *carPtr = (CarPtr)malloc(sizeof(Car));

        if (*carPtr != NULL)
        {
            (*carPtr)->leftPtr = NULL;
            strcpy((*carPtr)->carVIN, VIN);
            strcpy((*carPtr)->carMake, make);
            strcpy((*carPtr)->carModel, model);
            (*carPtr)->carBodyStyle = bodyStyle;
            (*carPtr)->carYear = year;
            (*carPtr)->carPrice = price;
            (*carPtr)->rightPtr = NULL;
        }
        else
        {
            puts("Memory issues... Node not created.");
        }

        return;
    }
    else
    { // otherwise, continue for apporiate place to insert by going left/right
        if (strcmp(VIN, (*carPtr)->carVIN) < 0)
        {
            // go left
            insertNode(&((*carPtr)->leftPtr), VIN, make, model, bodyStyle, year, price);
        }
        else if (strcmp(VIN, (*carPtr)->carVIN) > 0)
        {
            // go right
            insertNode(&((*carPtr)->rightPtr), VIN, make, model, bodyStyle, year, price);
        }
        else
        {
            // duplicate elimination
            printf("%s", "-duplicate-not-inserted");
        }
    }
}

void insertNodeWithDuplicates(CarPtr *carPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price)
{
    if (*carPtr == NULL) // Node can be inserted as a leaf node
    {
        *carPtr = (CarPtr)malloc(sizeof(Car));
        if (*carPtr != NULL)
        {
            (*carPtr)->leftPtr = NULL;
            strcpy((*carPtr)->carVIN, VIN);
            strcpy((*carPtr)->carMake, make);
            strcpy((*carPtr)->carModel, model);
            (*carPtr)->carBodyStyle = bodyStyle;
            (*carPtr)->carYear = year;
            (*carPtr)->carPrice = price;
            (*carPtr)->rightPtr = NULL;
        }
        else
        {
            puts("Memory issues... Node not created.");
        }

        return;
    }
    else
    { // otherwise, continue for apporiate place to insert by going left/right
        if (strcmp(VIN, (*carPtr)->carVIN) <= 0)
        {
            // go left
            insertNodeWithDuplicates(&((*carPtr)->leftPtr), VIN, make, model, bodyStyle, year, price);
        }
        else
        {
            // go right
            insertNodeWithDuplicates(&((*carPtr)->rightPtr), VIN, make, model, bodyStyle, year, price);
        }
    }
}

void preOrder(CarPtr carPtr)
{
    if (carPtr != NULL)
    {
        // printf("%d ", treePtr->data);
        printf("%s\t%s\t%s\t%c\t%u\t%.2f\n", carPtr->carVIN, carPtr->carMake, carPtr->carModel, carPtr->carBodyStyle, carPtr->carYear, carPtr->carPrice);
        preOrder(carPtr->leftPtr);
        preOrder(carPtr->rightPtr);
    }
}

void inOrder(CarPtr carPtr)
{
    if (carPtr != NULL)
    {
        inOrder(carPtr->leftPtr);
        // printf("%d ", treePtr->data);
        printf("%s\t%s\t%s\t%c\t%u\t%.2f\n", carPtr->carVIN, carPtr->carMake, carPtr->carModel, carPtr->carBodyStyle, carPtr->carYear, carPtr->carPrice);
        inOrder(carPtr->rightPtr);
    }
}

void inReverseOrder(CarPtr carPtr)
{
    if (carPtr != NULL)
    {
        inReverseOrder(carPtr->rightPtr);
        // printf("%d ", treePtr->data);
        printf("%s\t%s\t%s\t%c\t%u\t%.2f\n", carPtr->carVIN, carPtr->carMake, carPtr->carModel, carPtr->carBodyStyle, carPtr->carYear, carPtr->carPrice);
        inReverseOrder(carPtr->leftPtr);
    }
}

void postOrder(CarPtr carPtr)
{
    if (carPtr != NULL)
    {
        postOrder(carPtr->leftPtr);
        postOrder(carPtr->rightPtr);
        // printf("%d ", treePtr->data);
        printf("%s\t%s\t%s\t%c\t%u\t%.2f\n", carPtr->carVIN, carPtr->carMake, carPtr->carModel, carPtr->carBodyStyle, carPtr->carYear, carPtr->carPrice);
    }
}

/* search for key in tree */
CarPtr binaryTreeSearch(CarPtr carPtr, char searchKey[17])
{
    if (carPtr == NULL /* implies treePtr is NULL */)
    {
        // add code here to process search key not found
        return NULL;
    }
    else if (strcmp(searchKey, carPtr->carVIN) == 0 /* implies (key == treePtr->data) */)
    {
        // add code here to process search key found
        return carPtr;
    }
    else if (strcmp(searchKey, carPtr->carVIN) < 0 /* implies (key < treePtr->data) */)
    {
        // add code here to continue searching left subtree
        binaryTreeSearch(carPtr->leftPtr, searchKey);
    }
    else /* implies (key > treePtr->data) */
    {
        // add code here to search right tree
        binaryTreeSearch(carPtr->rightPtr, searchKey);
    }
}

/* deletes a node from the binary search tree */
void deleteNode(CarPtr *carPtr, char VIN[17])
{
    int found;
    CarPtr parentPtr, tempNodePtr, replacementNodePtr;

    /* if tree is empty */
    if (*carPtr == NULL)
    {
        printf("\nInventory is empty");
        return;
    }

    parentPtr = NULL;
    tempNodePtr = NULL;

    /* find the node to be deleted */
    searchNode(carPtr, VIN, &parentPtr, &tempNodePtr, &found);

    /* if the node is not found */
    if (found == 0)
    {
        printf("\n Car not found");
        return;
    }

    /* if the node to be deleted has two children */

    if (tempNodePtr->leftPtr != NULL && tempNodePtr->rightPtr != NULL)
    {
        //puts("Car has two children");
        parentPtr = tempNodePtr;
        replacementNodePtr = tempNodePtr->rightPtr;

        while (replacementNodePtr->leftPtr != NULL)
        {
            parentPtr = replacementNodePtr;
            replacementNodePtr = replacementNodePtr->leftPtr;
        }

        // tempNodePtr -> data = replacementNodePtr -> data ;
        // strcpy(tempNodePtr->carVIN, replacementNodePtr->carVIN);
        // tempNodePtr = replacementNodePtr;

        strcpy(tempNodePtr->carVIN, replacementNodePtr->carVIN);
        tempNodePtr = replacementNodePtr;

        free(replacementNodePtr);
        return;
    }

    /* if the node to be deleted has no child */

    if (tempNodePtr->leftPtr == NULL && tempNodePtr->rightPtr == NULL)
    {
        //puts("Car has no children");
        if (parentPtr->rightPtr == tempNodePtr)
        {
            //puts("Right Pointer");
            parentPtr->rightPtr = NULL;
        }
        else
        {
            //puts("Right Pointer");
            parentPtr->leftPtr = NULL;
        }

        free(tempNodePtr);
        return;
    }

    /* if the node to be deleted has only rightPtr */

    if (tempNodePtr->leftPtr == NULL && tempNodePtr->rightPtr != NULL)
    {
        //puts("Car has right child");
        if (parentPtr->leftPtr == tempNodePtr)
            parentPtr->leftPtr = tempNodePtr->rightPtr;
        else
            parentPtr->rightPtr = tempNodePtr->rightPtr;

        free(tempNodePtr);
        return;
    }

    /* if the node to be deleted has only left child */

    if (tempNodePtr->leftPtr != NULL && tempNodePtr->rightPtr == NULL)
    {
        //puts("Car has left child");
        if (parentPtr->leftPtr == tempNodePtr)
            parentPtr->leftPtr = tempNodePtr->leftPtr;
        else
            parentPtr->rightPtr = tempNodePtr->leftPtr;

        free(tempNodePtr);
        return;
    }
}

void searchNode(CarPtr *carPtr, char VIN[17], CarPtr *parentPtr, CarPtr *tempNodePtr, int *found)
{
    CarPtr tempPtr;
    tempPtr = *carPtr;
    *found = 0;
    *parentPtr = NULL;

    while (tempPtr != NULL)
    {
        if (strcmp(VIN, tempPtr->carVIN) == 0) // tempPtr -> data == value
        {
            printf("Car %s\t%s\t%s\t%c\t%u\t%.2f is being deleted\n", tempPtr->carVIN, tempPtr->carMake, tempPtr->carModel, tempPtr->carBodyStyle, tempPtr->carYear, tempPtr->carPrice);
            *found = 1;
            *tempNodePtr = tempPtr;
            return;
        }

        *parentPtr = tempPtr;
        if (strcmp(tempPtr->carVIN, VIN) > 0) // tempPtr -> data > value
            tempPtr = tempPtr->leftPtr;
        else
            tempPtr = tempPtr->rightPtr;
    }
}
