#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Define car with paramater types
struct car{
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

//Define function prototypes
CarPtr makeCar(char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price);
CarPtr addCar(CarPtr startPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price);
CarPtr removeCar(CarPtr startPtr, char VIN[17]);
void viewCar(CarPtr startPtr, char VIN[17]);
bool uniqueVIN(CarPtr startPtr, char VIN[17]);
void printCarList(CarPtr startPtr);
void displayMenu();
 
//Make car (Used by addCar)
CarPtr makeCar(char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price)
{
  CarPtr newPtr = malloc(sizeof(Car));
  if(newPtr == NULL)
  {
    puts("Issues with memory! Car could not be created...");
  }
  else{
    strcpy(newPtr->carVIN, VIN);
    strcpy(newPtr->carMake, make);
    strcpy(newPtr->carModel, model);
    newPtr->carBodyStyle = bodyStyle;
    newPtr->carYear = year;
    newPtr->carPrice = price;
  }
  return newPtr;
}

//Add Car
CarPtr addCar(CarPtr startPtr, char VIN[17], char make[30], char model[30], char bodyStyle, unsigned int year, float price)
{
  CarPtr previousPtr, currentPtr, newPtr;
  previousPtr = NULL;
  currentPtr = startPtr;
  newPtr = makeCar(VIN, make, model, bodyStyle, year, price);

  while (currentPtr != NULL && strcmp(currentPtr->carVIN, VIN) > 0)
  {
    previousPtr = currentPtr;
    currentPtr = currentPtr->nextPtr;
  }

  if(previousPtr == NULL)
  {
    newPtr->nextPtr = startPtr;
    startPtr = newPtr;
  }
  else{
    previousPtr->nextPtr = newPtr;
    newPtr->nextPtr = currentPtr;
  }
  return startPtr;
}

//Print full inventory
void printCarList(CarPtr starPtr)
{
  CarPtr tempPtr = starPtr;
  if(tempPtr == NULL)
  {
    puts("Inventory is empty, please add some cars!");
    return;
  }
  else{
    puts("Cars in inventory are:");
    puts("VIN\t\t\tMake\tModel\tBody\tYear\tPrice");
    while(tempPtr != NULL)
    {
      printf("%s\t%s\t%s\t%c\t%u\t$%.2f\n", tempPtr->carVIN, tempPtr->carMake, tempPtr->carModel, tempPtr->carBodyStyle, tempPtr->carYear, tempPtr->carPrice);
      tempPtr = tempPtr->nextPtr;
    }
  }
}

//Delete car by VIN
CarPtr removeCar(CarPtr startPtr, char VIN[17])
{
  CarPtr previousPtr, currentPtr, tempPtr;
  previousPtr = NULL;
  currentPtr = startPtr;
  
  if (startPtr == NULL)
  {
    puts("Nothing to delete!");
    return startPtr;
  }

  while (currentPtr != NULL &&  strcmp(currentPtr->carVIN, VIN) != 0)
  {
     previousPtr = currentPtr;
     currentPtr = currentPtr->nextPtr;
  }

  if(currentPtr == NULL) 
  {
    printf("Unable to find VIN %s in Inventory\n", VIN);
  }
  else if (previousPtr == NULL){ 
    tempPtr = startPtr;
    printf("Car %s %s %s %c %u $%.2f is being deleted...\n", tempPtr->carVIN, tempPtr->carMake, tempPtr->carModel, tempPtr->carBodyStyle, tempPtr->carYear, tempPtr->carPrice);
    startPtr = startPtr->nextPtr;
    free(tempPtr);
    
  }
  else{ 
    tempPtr = currentPtr;
    printf("Car %s %s %s %c %u $%.2f is being deleted...\n", tempPtr->carVIN, tempPtr->carMake, tempPtr->carModel, tempPtr->carBodyStyle, tempPtr->carYear, tempPtr->carPrice);
    previousPtr->nextPtr = currentPtr->nextPtr;
    free(tempPtr);
  }
  return startPtr;
}

//View car by VIN
void viewCar(CarPtr startPtr, char VIN[18])
{
  CarPtr currentPtr = startPtr;
  int position = 0;

  if(startPtr == NULL)
  {
    puts("Inventory empty, please add cars!");
    return;
  }

  while (currentPtr != NULL &&  strcmp(currentPtr->carVIN, VIN) != 0)
  {
     currentPtr = currentPtr->nextPtr;
     position++;
  }

  if(currentPtr == NULL)
  {
    printf("No car with VIN %s was found in inventory...", VIN);
  }
  else{
    printf("Car was found at position %d\n", position);
    puts("VIN\t\t\t    Make\tModel\tBody\tYear\tPrice");
    printf("%s\t\t\t    %s\t%s\t%c\t%u\t$%.2f\n", currentPtr->carVIN, currentPtr->carMake, currentPtr->carModel, currentPtr->carBodyStyle, currentPtr->carYear, currentPtr->carPrice);
  }
}

//Determine if a VIN is in use or not
bool uniqueVIN(CarPtr startPtr, char VIN[18])
{
  CarPtr currentPtr = startPtr;
  int position = 0;

  if(startPtr == NULL)
  {
    return true;
  }

  while (currentPtr != NULL &&  strcmp(currentPtr->carVIN, VIN) != 0)
  {
     currentPtr = currentPtr->nextPtr;
     position++;
  }

  if(currentPtr == NULL)
  {
    return true;
  }
  else{
    printf("Car with VIN %s already exists!\n", VIN);
    return false;
  }
}

//Display menu options
void displayMenu () 
{
  printf ("\t1: Insert Car into Inventory\n");
  printf ("\t2: Remove Car from Inventory by VIN\n");
  printf ("\t3: Search for car by VIN\n");
  printf ("\t4: Display full inentory\n");
  printf ("\t5: Exit\n");
  printf ("\tEnter Choice: ");
} 
 

