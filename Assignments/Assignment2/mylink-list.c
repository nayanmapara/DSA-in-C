#include "mylink-list.h"
 
int main () 
{
  //define pointers
  CarPtr strPtr;
  strPtr = NULL;
  
  //var for menu choice
  int choice;

  //fields for creating car object
  char VIN[18], make[30], model[30];
  char bodyStyle;
  unsigned int year;
  float price;

  displayMenu ();
  scanf ("%d", &choice);

  //Exit when user selects 5
  while (choice != 5)
  {
    switch (choice) 
    {
       case 1: //Add new car
          printf("\nEnter car VIN: ");
          scanf("%17s", VIN);
          //Search for if VIN exists
          if(uniqueVIN(strPtr, VIN) == false){
            break;
          }
          printf("Enter Make: ");
          scanf("%29s", make);
          printf("Enter Model: ");
          scanf("%29s", model);
          printf("Enter year: ");
          scanf("%u", &year);
          printf("Enter bodystyle as character (C - Car, S - SUV, T - Truck): ");
          scanf(" %c", &bodyStyle);
          printf("Enter price: $");
          scanf("%f", &price);
          strPtr = addCar(strPtr,VIN, make, model, bodyStyle, year, price);
            printCarList (strPtr);
            printf ("\n");
           break;
       case 2: printf ("\nDelete car by VIN: "); //Delete car by VIN
           scanf ("%17s", VIN);
           strPtr = removeCar(strPtr, VIN);
          printCarList(strPtr);
           printf ("\n");
               break;
       case 3: printf ("\nSearch Car by VIN : "); //Search car by VIN
           scanf ("%s", VIN);
           viewCar(strPtr, VIN);
           printf ("\n");
           break;
       case 4: printCarList (strPtr); //Print full list
           printf ("\n");
           break;
       default:
           printf ("Invalid Option... Please Try Again \n");
           break;
    }
    displayMenu ();
    scanf ("%d", &choice);
  }
  
}