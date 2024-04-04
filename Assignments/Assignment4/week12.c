#include <stdio.h>
#include <stdlib.h>

#define N 13

typedef struct node {
    int key;
    struct node *nextPtr;
} Node, *NodePtr;

// Function prototypes
NodePtr newNode(int key);                             // Create new node
void printNode(NodePtr frontPtr);                     // Print hash table
void hashTableInsert(NodePtr hash[N], int key, int size);

int main() {
    int j, key, count = 0;                            // Declare count and initialize
    FILE *in = fopen("input.in", "r");                // reading input from a text file

    NodePtr hash[N];                                  // create the hash table as an array of pointers;

    for (j = 0; j < N; j++) {                         // initialize table of pointers to NULL
        hash[j] = NULL;
    }

    while (fscanf(in, "%d", &key) == 1) {
        int k = (2 * key + 5) % N;
        if (hash[k] != NULL) { 
            NodePtr currPtr = hash[k]; 
            while (currPtr != NULL) {
                if (currPtr->key == key) {
                    break;
                }
                currPtr = currPtr->nextPtr;
            }
            if (currPtr != NULL) {
                continue;
            }
        }

        hashTableInsert(hash, key, N);          
        count++;
    }

    printf("There are %d items in the hash table\n", count);
    for (j = 0; j < N; j++) {
        printf("Hash [%d] -> ", j);
        printNode(hash[j]);
    }
    fclose(in);
    return 0;
}

NodePtr newNode(int key) {
    NodePtr newNode = malloc(sizeof(Node));  
    newNode->key = key;
    newNode->nextPtr = NULL;
    return newNode;
}

void printNode(NodePtr frontPtr) {
    while (frontPtr != NULL) {
        printf("%d -> ", frontPtr->key);
        frontPtr = frontPtr->nextPtr;
    }
    puts("");                                    // To indicate the end of the list
}

// Rmoving duplicate values from the hash table
void hashTableInsert(NodePtr hash[N], int key, int size) {
    int k = (2 * key + 5) % size;
    NodePtr currPtr = hash[k];
    NodePtr prevPtr = NULL;

    while (currPtr != NULL && key > currPtr->key) {
        prevPtr = currPtr;
        currPtr = currPtr->nextPtr;
    }
    NodePtr newPtr = newNode(key);
    newPtr->nextPtr = currPtr;

    if (prevPtr == NULL) {
        hash[k] = newPtr;
    } else {
        prevPtr->nextPtr = newPtr;
    }
}
