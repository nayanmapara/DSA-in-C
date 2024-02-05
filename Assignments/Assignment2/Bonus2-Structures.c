#include <stdio.h>

typedef struct inventory
{
    char partName[30];
    int partNumber;
    float price;
    int stock;
    int reorder;
} Inventory;

typedef struct address
{
    char streetAddress[25];
    char city[20];
    char state[3];
    char zipCode[6];
} Address;

typedef struct student
{
    char lastName[15];
    char firstName[15];
    Address homeAddress;
} Student;

struct customer
{
    char lastName[15];
    char firstName[15];
    int customerNumber;
    struct
    {
        char phoneNumber[11];
        char address[50];
        char city[15];
        char state[3];
        char zipCode[6];
    } personal;
} customerRecord, *customerPtr;


int main()
{
    customerPtr = &customerRecord;

    Inventory inventory = {"Hammer", 123, 12.50, 10, 5};
    Student student = {"Smith", "John", {"123 Main St", "Anytown", "NY", "12345"}};
    Address address = {"123 Main St", "Anytown", "NY", "12345"};
    customerRecord = (struct customer){"Doe", "Jane", 123, {"123 Main St", "Anytown", "NY", "12345"}};

    puts("Inventory");
    printf("Part Name: %s\n", inventory.partName);
    printf("Part Number: %d\n", inventory.partNumber);
    printf("Price: %.2f\n", inventory.price);
    printf("Stock: %d\n", inventory.stock);
    printf("Reorder: %d\n", inventory.reorder);

    puts("Student");
    printf("Last Name: %s\n", student.lastName);
    printf("First Name: %s\n", student.firstName);
    printf("Street Address: %s\n", student.homeAddress.streetAddress);
    printf("City: %s\n", student.homeAddress.city);
    printf("State: %s\n", student.homeAddress.state);
    printf("Zip Code: %s\n", student.homeAddress.zipCode);

    puts("Address");
    printf("Street Address: %s\n", address.streetAddress);
    printf("City: %s\n", address.city);
    printf("State: %s\n", address.state);
    printf("Zip Code: %s\n", address.zipCode);

    puts("Customer");
    printf("Last Name: %s\n", customerPtr->lastName);
    printf("First Name: %s\n", customerPtr->firstName);
    printf("Customer Number: %d\n", customerPtr->customerNumber);
    printf("Phone Number: %s\n", customerPtr->personal.phoneNumber);
    printf("Address: %s\n", customerPtr->personal.address);
    printf("City: %s\n", customerPtr->personal.city);
    printf("State: %s\n", customerPtr->personal.state);
    printf("Zip Code: %s\n", customerPtr->personal.zipCode);
}

