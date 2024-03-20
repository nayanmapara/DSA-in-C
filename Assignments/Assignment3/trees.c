// Binary Tree Example
#include "trees.h"

int main( void )
{ 
   CarPtr rootPtr = NULL; // Define the root pointer for the tree

    char input[100];
    int choice;

    char VIN[18], make[30], model[30];
    char bodyStyle;
    unsigned int year;
    float price;

    printf("Car Dealership Tree Menu:\n");
    printf("1. Insert new car\n");
    printf("2. Print cars in pre-order\n");
    printf("3. Print cars in in-order\n");
    printf("4. Print cars in reverse order\n");
    printf("5. Print cars in post-order\n");
    printf("6. Exit\n");

    fgets(input, sizeof(input), stdin);
    choice = strtol(input, NULL, 10);

    while (choice != 6) {
        switch (choice) {
            case 1:
                printf("Enter car details:\n");
                printf("VIN: ");
                fgets(VIN, sizeof(VIN), stdin);
                VIN[strcspn(VIN, "\n")] = '\0';

                printf("Make: ");
                fgets(make, sizeof(make), stdin);
                make[strcspn(make, "\n")] = '\0';
                
                printf("Model: ");
                fgets(model, sizeof(model), stdin);
                model[strcspn(model, "\n")] = '\0';
                
                printf("Year: ");
                fgets(input, sizeof(input), stdin);
                year = strtol(input, NULL, 10);

                printf("Body Style (C - Car, S - SUV, T - Truck): ");
                fgets(input, sizeof(input), stdin);
                bodyStyle = input[0];

                printf("Price: ");
                fgets(input, sizeof(input), stdin);
                price = strtof(input, NULL);


                insertNode(&rootPtr, VIN, make, model, bodyStyle, year, price);
                break;
            case 2:
                printf("Cars in pre-order:\n");
                preOrder(rootPtr);
                break;
            case 3:
                printf("Cars in in-order:\n");
                inOrder(rootPtr);
                break;
            case 4:
                printf("Cars in reverse order:\n");
                inReverseOrder(rootPtr);
                break;
            case 5:
                printf("Cars in post-order:\n");
                postOrder(rootPtr);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        printf("\nCar Dealership Tree Menu:\n");
        printf("1. Insert new car\n");
        printf("2. Print cars in pre-order\n");
        printf("3. Print cars in in-order\n");
        printf("4. Print cars in reverse order\n");
        printf("5. Print cars in post-order\n");
        printf("6. Exit\n");

        fgets(input, sizeof(input), stdin);
        choice = strtol(input, NULL, 10);
    }

    return 0;
}

