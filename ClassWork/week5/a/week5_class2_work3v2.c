/*
Write a program that creates a structure called "Friends". You should house at least 3 different pieces / types of data in your structures. Furthermore, create an array of N friends, where N is a predefined constant, load the array and output the details of your friends. Include in your data items, a piece of data called "price", which is the price of a bus ticket that each friend would need to travel to your house. Your program should calculate the total cost for all friends travelling to your house.

Ensure to output the friends' details using a function.
*/ 

#include <stdio.h>
#define N 3

// structure definition
struct friends
{ 
  unsigned int id;
  char name[20];
  float price;
};

// structure renaming
typedef struct friends Friends;

void printDetails(Friends x);

int main ()
{
    size_t i;
    float totalCost = 0;
    Friends any[N];

    for (i = 0; i < N; i++)
    {
        printf("Enter ID of friend #%Zu: ", i + 1);
        scanf("%u", &any[i].id);

        printf("Enter Name of friend #%Zu: ", i + 1);
        scanf("%19s", any[i].name);

        printf("Enter the price to get to friend #%Zu: ", i + 1);
        scanf("%f", &any[i].price);

        totalCost += any[i].price;
    }

    printf("Version 2: Passing structure to function\n");
    printf("ID\tName\tPrice\n");
    for (i = 0; i < N; i++)
    {
        printDetails(any[i]);
    }
    printf("Total cost: %.2f\n", totalCost);
}

void printDetails(Friends x)
{
    printf("%u\t%s\t%.2f\n", x.id, x.name, x.price);
};