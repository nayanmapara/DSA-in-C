
/* 
Program creates an hashtable from an input file of numbers. The program places the numbers in a hash table, using chaining as the collision resolution scheme.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 13

// Setup structure node 
typedef struct node {
  int key;
  struct node *nextPtr;
} Node, *NodePtr;

// Function prototypes
NodePtr newNode(int key);/* Create new node */
void printNode(NodePtr frontPtr);/* Insert into hashtable*/
void hashTableInsert(NodePtr hash[N], int key, int size);/* Print hash table  */

int main(){
  int j, key, count = 0;
  FILE *in = fopen("input.in","r");  // reading input from a text file
  
  NodePtr hash[N];// create the hash table as an array of pointers;
  
  for(j=0; j<N; j++){// initialize table of pointers to NULL
    hash[j] = NULL;
  }

  while(fscanf(in, "%d", &key ) == 1){
    /* Insert into hashtable*/ 
    hashTableInsert(hash, key, N);
    count++;
  }

  // print out the values inserted into the hash table
  printf("There are %d values in the hash table\n", count);
  for (j = 0; j<N ; j++){
      // add code: print out the list of values for each index in table
      printf("hash[%d]->", j);
      printNode(hash[j]);   
  }
  fclose(in);

}

// Function definition

NodePtr newNode(int key)/* Create new node */
{
  NodePtr newPtr = malloc(sizeof(Node));
  newPtr->key = key;
  newPtr->nextPtr = NULL;
  return newPtr;
}

void printNode(NodePtr frontPtr)/* Print hash table  */
{
  while (frontPtr != NULL)
  {
    printf("%d->", frontPtr->key);
    frontPtr = frontPtr->nextPtr;
  }
  
  puts("");

 
  
}


void hashTableInsert(NodePtr hash[N], int key, int size)/* Insert into hashtable*/
{
  // setup the compression map h(k) = inKey % N;
  int k = key % size;

  // initialise currPtr pointer for traversal of list ;
  NodePtr currPtr = hash[k];
  
  // initialise prevPtr pointer for traversal of list ;
  NodePtr prevPtr = NULL;

  // go to appropriate insert-location in the current list 
  while (currPtr != NULL && currPtr->key < key)
  {
    prevPtr = currPtr;
    currPtr = currPtr->nextPtr;
  }
  
  // create new node
  NodePtr newPtr = newNode(key);
  
  // insert node into place
  newPtr->nextPtr = currPtr;
  if (prevPtr == NULL)
  {
    hash[k] = newPtr;
  } else {
    prevPtr->nextPtr = newPtr;
  }
}

