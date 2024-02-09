//Activity 1: include the link-list header file
#include "link-list1.h"
 
int main () 
{
  //Activity 2: creating list pointer
  ItemPtr startPtr;
  //Activity 3: initialising the start of the list 
  startPtr = NULL;
      
  int value, choice;
  menu ();
  scanf ("%d", &choice);
  while (choice != 5)
  {
    switch (choice) //Activity 4: Test your link list tasks
    {
       case 1: printf ("\nEnter Value for Item for Insertion: ");
               scanf ("%d", &value);
           startPtr = addItem (startPtr, value);
           printList (startPtr);
           printf ("\n");
           break;
       case 2: printf ("\nEnter Item for deletion : ");
           scanf ("%d", &value);
           startPtr = removeItem (startPtr, value);
           printList (startPtr);
           printf ("\n");
               break;
       case 3: //printf ("\nEnter Item Number to View : ");
           //scanf ("%d", &value);
           //viewItem (startPtr, value);
           //printf ("\n");
           break;
       case 4: printList (startPtr);
           printf ("\n");
           break;
       default:
           printf ("Invalid Option... Please Try Again \n");
           break;
    }
      
    menu ();
    scanf ("%d", &choice);
  }
  
}// end of main