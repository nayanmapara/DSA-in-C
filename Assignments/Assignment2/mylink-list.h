// Header file containing link-list definitions & implementation methods
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definition
struct item{ // items on a shelf in a supermarket
   int itemId;
   char itemSection;
   char itemName[20];
   struct item *nextPtr;
};

// Structure renaming
typedef struct item Item;
typedef struct item *ItemPtr;

/*Function Prototypes*/
ItemPtr makeItem(int value, char section, char name[20]);
ItemPtr addItem(ItemPtr sPtr, int value, char section, char name[20]);
void printList(ItemPtr sPtr);
//removeItem ();
//viewItem ();
void menu ();
 
/*******Function Definitions******/
//makeItem () {}
//addItem () {}
//printList () {}
//removeItem (){}
//viewItem (){}
ItemPtr makeItem(int value, char section, char name[20])
{
  ItemPtr newPtr = malloc(sizeof(Item));
  if(newPtr == NULL)
  {
     puts("Memory Issues... Item Not Created");
  }
  else{
     newPtr->itemId = value;
     newPtr->itemSection = section;
     strcpy (newPtr->itemName,name);
     newPtr->nextPtr = NULL;
  }
  return newPtr;
}

ItemPtr addItem(ItemPtr sPtr, int value, char section, char name[20])
{
  ItemPtr previousPtr, currentPtr, newPtr;
  previousPtr = NULL;
  currentPtr = sPtr;
  newPtr = makeItem(value, section, name);
  
  while (currentPtr != NULL && value > currentPtr->itemId)
  {
     previousPtr = currentPtr;
     currentPtr = currentPtr->nextPtr;
  }
  
  // exit traversal
  if(previousPtr == NULL)
  {
    newPtr->nextPtr = sPtr;
    sPtr = newPtr;
  }
  else{
    previousPtr->nextPtr = newPtr;
    newPtr->nextPtr = currentPtr;
  }
  return sPtr;
}

void printList(ItemPtr sPtr)
{
  ItemPtr tempPtr = sPtr;
  if(tempPtr == NULL)
  {
     puts("List is Empty... Nothing to Print");
     return;
  }
  else{
     puts("The Items in the List are");
     while(tempPtr != NULL)
     {
       printf("%d %c %s\n", tempPtr->itemId,tempPtr->itemSection, tempPtr->itemName );
       tempPtr = tempPtr->nextPtr;
     }
  
  }
}

void menu () 
{
  printf ("\t1: Insert Item into Ordered List\n");
  printf ("\t2: Remove Item from List\n");
  printf ("\t3: View Item from List\n");
  printf ("\t4: Printing the List\n");
  printf ("\t5: Exit\n");
  printf ("\tEnter Choice: ");
} 
 

