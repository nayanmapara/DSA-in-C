#include "queues.h"

int main( void )
{ 
    // add code to initialize headPtr
    CarPtr headPtr = NULL;
    // add code to initialize tailPtr
    CarPtr tailPtr = NULL;


    // var for menu choice
   char input[100];

   // fields for creating car object
   char VIN[18], make[30], model[30];
   char bodyStyle;
   unsigned int year;
   float price;
   
   int choice; // user's menu choice
   int item; // integer input by user

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%d", &choice );

   // while user does not enter 3
   while ( choice != 6 ) { 

      switch( choice ) { 
         case 1:
            printf("Enter car VIN: ");
            scanf("%17s", VIN);
            // fgets(VIN, sizeof(VIN), stdin);
            // VIN[(strcspn(VIN, "\n"))] = '\0';
            // Search for if VIN exists
            if (uniqueVIN(headPtr, VIN) == false)
            {
            break;
            }
            // fgets(make, sizeof(make), stdin);
            printf("Enter Make: ");
            scanf("%29s", make);
            // fgets(make, sizeof(make), stdin);
            // make[(strcspn(make, "\n"))] = '\0';

            printf("Enter Model: ");
            scanf("%29s", model);
            // fgets(model, sizeof(model), stdin);
            // model[(strcspn(model, "\n"))] = '\0';

            printf("Enter year: ");
            scanf("%u", &year);
            // fgets(input, sizeof(input), stdin);
            // input[(strcspn(input, "\n"))] = '\0';
            // year = strtol(input, NULL, 10);

            printf("Enter bodystyle as character (C - Car, S - SUV, T - Truck): ");
            scanf(" %c", &bodyStyle);

            // bodyStyle = getchar();
            // getchar();

            printf("Enter price: $");
            scanf("%f", &price);

            // fgets(input, sizeof(input), stdin);
            // input[(strcspn(input, "\n"))] = '\0';
            // price = strtof(input, NULL);


            enqueue(&headPtr, &tailPtr, VIN, make, model, bodyStyle, year, price);
            printQueue(headPtr); 
            break;
        
         case 2:
           if(!isEmpty(headPtr))
           {
            dequeue(&headPtr,&tailPtr);
           }
           printQueue(headPtr);
           break;

         case 3:
            frontOfQueue(headPtr);
            break;

         case 4:
            endOfQueue(tailPtr);
            break;

         case 5:
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




