#include "car-dealership-stack.h"

int main()
{
  // define pointers
  CarPtr stackPtr;
  stackPtr = NULL;

  // var for menu choice
  char input[100];
  int choice;

  // fields for creating car object
  char VIN[18], make[30], model[30];
  char bodyStyle;
  unsigned int year;
  float price;

  // displayMenu ();
  stackMenu();
  fgets(input, sizeof(input), stdin);
  input[(strcspn(input, "\n"))] = '\0';
  choice = strtol(input, NULL, 10);

  // Exit when user selects 5
  while (choice != 6)
  {
    switch (choice)
    {
    case 1: // Print top of stack
      if (!isEmpty(stackPtr))
      {
        // Get car from top of stack
        topOfCarStack(stackPtr);
      }
      else{puts("Empty...");}
      break;
    case 2: // Print top of stack
      bottomOfCarStack(stackPtr);
      // printf ("\n");
      break;
    case 3: // Add new car
      printf("Enter car VIN: ");
      // scanf("%17s", VIN);
      fgets(VIN, sizeof(VIN), stdin);
      VIN[(strcspn(VIN, "\n"))] = '\0';
      // Search for if VIN exists
      if (uniqueVIN(stackPtr, VIN) == false)
      {
        break;
      }
      // fgets(make, sizeof(make), stdin);
      printf("Enter Make: ");
      // scanf("%29s", make);
      fgets(make, sizeof(make), stdin);
      make[(strcspn(make, "\n"))] = '\0';

      printf("Enter Model: ");
      // scanf("%29s", model);
      fgets(model, sizeof(model), stdin);
      model[(strcspn(model, "\n"))] = '\0';

      printf("Enter year: ");
      // scanf("%u", &year);
      fgets(input, sizeof(input), stdin);
      input[(strcspn(input, "\n"))] = '\0';
      year = strtol(input, NULL, 10);

      printf("Enter bodystyle as character (C - Car, S - SUV, T - Truck): ");
      // scanf(" %c", &bodyStyle);

      bodyStyle = getchar();
      getchar();

      printf("Enter price: $");
      // scanf("%f", &price);
      fgets(input, sizeof(input), stdin);
      input[(strcspn(input, "\n"))] = '\0';
      price = strtof(input, NULL);

      // This is where the magic happens.....
      stackPtr = pushCar(stackPtr, VIN, make, model, bodyStyle, year, price);
      printCarStack(stackPtr);
      break;
    case 4:
      printf("\nRemove car from stack: "); // Pop car from stack
      if (!isEmpty(stackPtr))
      {
        //	pop node from stack
        stackPtr = popCar(stackPtr);
      }
      // print the current stack nodes
      printCarStack(stackPtr);
      break;
    case 5:
      printCarStack(stackPtr); // Print full list
      // printf ("\n");
      break;
    default:
      printf("Invalid Option... Please Try Again");
      break;
    }

    printf("Do you want to continue? (Y/N) ");
    fgets(input, sizeof(input), stdin);
    input[(strcspn(input, "\n"))] = '\0';
    choice = input[0];
    if (choice == 'N' || choice == 'n')
    {
      break;
    }

    // fgets(input, sizeof(input),stdin);
    // displayMenu ();
    stackMenu();

    fgets(input, sizeof(input), stdin);
    input[(strcspn(input, "\n"))] = '\0';
    choice = strtol(input, NULL, 10);
  }
}