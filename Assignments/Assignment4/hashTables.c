/*
Program creates an hashtable from an input file of numbers. The program places the numbers in a hash table, using chaining as the collision resolution scheme.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 13

// Setup structure node
typedef struct node
{
    int key;
    struct node *nextPtr;
} Node, *NodePtr;
// Function prototypes

NodePtr newNode(int key);                                 /* Create new node */
void printNode(NodePtr frontPtr);                         /* Print hash table  */
void hastTableInsert(NodePtr hash[N], int key, int size); /* Insert into hashtable*/
int main()
{
    int j, key, count = 0;
    FILE *in = fopen("input.in", "r"); // reading input from a text file

    NodePtr hash[N]; // create the hash table as an array of pointers;

    for (j = 0; j < N; j++) // initialize table of pointers to NULL
    {
        hash[j] = NULL;
    }
    while (fscanf(in, "%d", &key) == 1)
    {
        /* Insert into hashtable*/
        hastTableInsert(hash, key, N);
        count++;
    }

    // print out the values inserted into the hash table
    printf("There are %d", count);
    for (j = 0; j < N; j++)
    {
        // add code: print out the list of values for each index in table
        printf("Hash [%d] -> ", j);
        printNode(hash[j]);
    }
    fclose(in);
}

// Function definition

NodePtr newNode(int key) /* Create new node */
{
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newPtr->key = key;
    newPtr->nextPtr = NULL;
    return newPtr;
}

void printNode(NodePtr frontPtr) /* Print hash table  */
{
    while (frontPtr != NULL)
    {
        printf("%d->", frontPtr->key);
        frontPtr = frontPtr->nextPtr;
    }
    puts("");
}

void hastTableInsert(NodePtr hash[N], int key, int size) /* Insert into hashtable*/
{
    // setup the compression map h(k) = inKey % N;
    int k = key % size;
    NodePtr currPtr = hash[k]; // initialise currPtr pointer for traversal of list ;
    NodePtr prevPtr = NULL;    // initialise prevPtr pointer for traversal of list ;

    // go to appropriate insert-location in the current list
    while (currPtr != NULL && key > currPtr->key)
    {
        prevPtr = currPtr;
        currPtr = currPtr->nextPtr;
    }
    NodePtr newPtr = newNode(key); // create new node
    newPtr->nextPtr = currPtr;     // insert node into place
    if (prevPtr == NULL)
    {
        hash[k] = newPtr; // inserting at front
    }
    else
    {
        prevPtr->nextPtr = newPtr;
    }
}