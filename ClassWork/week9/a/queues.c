#include "queues.h"

int main( void )
{ 
    // add code to initialize headPtr
    QueueNodePtr headPtr = NULL;
    // add code to initialize tailPtr
    QueueNodePtr tailPtr = NULL;
   
   int choice; // user's menu choice
   int item; // integer input by user

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%d", &choice );

   // while user does not enter 3
   while ( choice != 3 ) { 

      switch( choice ) { 
         case 1:
            printf("Enter an integer: ");
            scanf(" %d", &item);
            enqueue(&headPtr, &tailPtr, item);
            printQueue(headPtr); 
            break;
        
         case 2:
           if(!isEmpty(headPtr))
           {
            dequeue(&headPtr,&tailPtr);
           }
           printQueue(headPtr);
           break;
         
         default:
            puts( "Invalid choice.\n" );
            break;
      } // end switch

      instructions();
      printf( "%s", "? " );
      scanf( "%d", &choice );
   } // end while

   puts( "End of run." );
} // end main




