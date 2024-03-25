// Binary Tree Example
#include "tree.h"

int main(void)
{
    CarPtr rootPtr = NULL;   // Define the root pointer for the tree
    CarPtr searchPtr = NULL; // Define the search pointer for the tree

    char input[100];
    int choice;
    char VIN[18], make[30], model[30];
    char bodyStyle;
    unsigned int year;
    float price;

    printf("Car Dealership Tree Menu:\n");
    printf("1. Insert new car\n");
    printf("2. Delete car by VIN\n");
    printf("3. Search for a car by VIN\n");
    printf("4. Print cars in pre-order\n");
    printf("5. Print cars in post-order\n");
    printf("6. Print cars in order\n");
    printf("7. Exit\n");

    fgets(input, sizeof(input), stdin);
    choice = strtol(input, NULL, 10);

    while (choice != 7)
    {
        switch (choice)
        {
        case 1:
            printf("Enter car details:\n");
            printf("VIN: ");
            fgets(VIN, sizeof(VIN), stdin);
            VIN[strcspn(VIN, "\n")] = '\0';

            // Unique VIN enforcement
            searchPtr = binaryTreeSearch(rootPtr, VIN);
            if (searchPtr != NULL)
            {
                printf("Car with VIN %s already in tree!\n", VIN);
                break;
            }

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
            printf("Delete car by VIN:\n");
            printf("VIN: ");
            fgets(VIN, sizeof(VIN), stdin);
            VIN[strcspn(VIN, "\n")] = '\0';
            deleteNode(&rootPtr, VIN);
            break;
        case 3:
            printf("Search for car by VIN: ");
            fgets(VIN, sizeof(VIN), stdin);
            VIN[strcspn(VIN, "\n")] = '\0';
            searchPtr = binaryTreeSearch(rootPtr, VIN);
            if (searchPtr == NULL)
                printf("No, car with VIN %s not found in tree\n", VIN);
            else
                printf("Car with VIN %s is found in tree\n", searchPtr->carVIN);
                printf("%s\t%s\t%s\t%c\t%u\t%.2f\n", searchPtr->carVIN, searchPtr->carMake, searchPtr->carModel, searchPtr->carBodyStyle, searchPtr->carYear, searchPtr->carPrice);
            break;
        case 4:
            printf("Cars in pre-order:\n");
            preOrder(rootPtr);
            break;
        case 5:
            printf("Cars in post-order:\n");
            postOrder(rootPtr);
            break;
        case 6:
            printf("Cars in in-order:\n");
            inOrder(rootPtr);
            break;

        default:
            printf("Invalid option. Please try again.\n");
            break;
        }

        
        printf("\nCar Dealership Tree Menu:\n");
        printf("1. Insert new car\n");
        printf("2. Delete car by VIN\n");
        printf("3. Search for a car by VIN\n");
        printf("4. Print cars in pre-order\n");
        printf("5. Print cars in post-order\n");
        printf("6. Print cars in order\n");
        printf("7. Exit\n");

        fgets(input, sizeof(input), stdin);
        choice = strtol(input, NULL, 10);
    }

    system("clear");
    system("gcc -o main_program main.c");	// compile main.c
    system("./main_program");	// run main.c

    return 0;
}
