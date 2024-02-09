// Header file containing link-list definitions & implementation methods
#include <stdio.h>
#include <stdlib.h>

// Structure Definition
struct item{
   int data;
   struct item *nextPtr;
};

// Structure renaming
typedef struct item Item;
typedef struct item *ItemPtr;

/*Function Prototypes*/
ItemPtr makeItem(int value);
ItemPtr addItem(ItemPtr sPtr, int value);
void printList(ItemPtr sPtr);
ItemPtr removeItem (ItemPtr, int value);
//viewItem ();
void menu ();
 
/*******Function Definitions******/
//makeItem () {}
//addItem () {}
//printList () {}
//removeItem (){}
//viewItem (){}
ItemPtr makeItem(int value)
{
  ItemPtr newPtr = (ItemPtr) malloc(sizeof(Item));
  if(newPtr == NULL)
  {
     puts("Memory Issues... Item Not Created");
  }
  else{
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

ItemPtr removeItem(ItemPtr sPtr, int value)
{
  ItemPtr previousPtr, currentPtr, tempPtr;
  previousPtr = NULL;
  currentPtr = sPtr;
  // revisit here
  if (sPtr = NULL)
  {
    puts("Nothing to print");
  }

  while (currentPtr != NULL && value != currentPtr->data)
  {
     previousPtr = currentPtr;
     currentPtr = currentPtr->nextPtr;
  }
  
  // exit traversal
  if(currentPtr == NULL) // check if node not in list
  {
    printf("%d is [not] found in the list\n", value);
  }
  else if (previousPtr == NULL){ // node found at front of list
    tempPtr = sPtr;
    printf("Node %d is being deleted...\n", tempPtr->data);// inform user
    sPtr = sPtr->nextPtr;
    free(tempPtr);
    printf("Node %d has been deleted", value);
  }
  else{ // node found elsewhere in list

  }
  return sPtr;
}

void printList(ItemPtr sPtr)
{
  ItemPtr tempPtr = sPtr;
  if(tempPtr == NULL)
  {
     puts("List is Empty... Nothing to Delete");
     return;
  }
  else{
     puts("The Items in the List are");
     while(tempPtr != NULL)
     {
       printf("%d->", tempPtr->data);
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