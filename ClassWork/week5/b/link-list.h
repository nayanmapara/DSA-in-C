// Header file containing link-list definitions & implementation methods
#include <stdio.h>
#include <stdlib.h>

// Structure Definition

struct item
{
    int data;
    struct item *nextPtr;
};

typedef struct item Item;
typedef struct item *ItemPtr;

ItemPtr makeItem(int value);
ItemPtr addItem(ItemPtr sPtr, int value);
void printList(ItemPtr sPtr);

ItemPtr makeItem(int value)
{
    ItemPtr newPtr = (ItemPtr)malloc(sizeof(Item));
    if (newPtr == NULL)
    {
        puts("Memory Issues... Item not created");
    }
    else
    {
        newPtr->data = value;
        newPtr->nextPtr = NULL;
    }
    return newPtr;
}

ItemPtr addItem(ItemPtr sPtr, int value)
{
    ItemPtr previousPtr, currentPtr, newPtr;
    previousPtr = NULL;
    currentPtr = sPtr;
    newPtr = makeItem(value);

    while (currentPtr != NULL && value > currentPtr->data)
    {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }

    if ( previousPtr == NULL)
    {
        newPtr->nextPtr = sPtr;
        sPtr = newPtr;
    }
    else
    {
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }
    return sPtr;
    
}

void printList(ItemPtr sPtr)
{
    ItemPtr tempPtr = sPtr;
    if (tempPtr == NULL)
    {
        puts("List is empty... Nothing to print");
        return;
    }
    else
    {
        puts("The items in the list are: ");
        while (tempPtr != NULL)
        {
            printf("%d --> ", tempPtr->data);
            tempPtr = tempPtr->nextPtr;
        }
        
    }
}

// Structure renaming

/*Function Prototypes*/

//makeItem ();
//addItem ();
//printList ();
//removeItem ();
//viewItem ();
void menu ();
 
/*******Function Definitions******/
//makeItem () {}
//addItem () {}
//printList () {}
//removeItem (){}
//viewItem (){}

void menu () 
{
  printf ("\t1: Insert Item into Ordered List\n");
  printf ("\t2: Remove Item from List\n");
  printf ("\t3: View Item from List\n");
  printf ("\t4: Printing the List\n");
  printf ("\t5: Exit\n");
  printf ("\tEnter Choice: ");
} 
 

