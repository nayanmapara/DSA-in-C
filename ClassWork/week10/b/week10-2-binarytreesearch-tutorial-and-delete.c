/*
(Binary Tree Search Tutorial Question)
 Write function binaryTreeSearch that attempts to locate a specified value in a binary search tree. The function should take as arguments a pointer to the root node of
the binary tree and a search key to be located. If the node containing the search key is found, the function should return a pointer to that node; otherwise, the function should return a NULL pointer.
*/
//ANS:


/* Exercise Solution */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

/* TreeNode structure definition */
struct treeNode{
  struct treeNode *leftPtr;
  int data;
  struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef struct treeNode *TreeNodePtr;

/* function prototypes */

//Add Code: binaryTreeSearch () 
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, int key);
void deleteNode( TreeNodePtr *treePtr, int value );
void searchNode ( TreeNodePtr *treePtr, int value, TreeNodePtr *parentPtr, TreeNodePtr *tempNodePtr, int *found );

void insertNode (TreeNodePtr * treePtr, int value);
void inOrder(TreeNodePtr treePtr);

int main (void)
{
  int i;			/* loop counter */
  int item;			/* random value to insert in tree */
  int searchKey;		/* value to search for */
  TreeNodePtr rootPtr = NULL; // Declare and initialise pointer to root of tree	
  
  // Add Code: Declare pointer to search-node 
  TreeNodePtr searchPtr = NULL;

  srand (time (NULL));		/* randomize */
  printf ("The numbers being placed in the tree are:\n");

  /* insert random values between 1 and 20 in the tree */
  for (i = 1; i <= 10; i++)
    {
      item = 1 + rand () % 20;
      printf ("%3d", item);
      insertNode (&rootPtr, item);
    }				/* end for */

    puts("");
    puts("The values in the tree are: ");
    inOrder(rootPtr);
    puts("");

  
  // add code to get search-key from user
  printf("Enter the value to search for: ");
  scanf("%d", &searchKey);
    
  // add code to perform the search
  searchPtr = binaryTreeSearch(rootPtr, searchKey);
    
  /* determine if value is found or not*/
  if (searchPtr == NULL)
  {
    printf("No... value %d is [not] in the tree\n", searchKey);
  } else {
    printf("Yes... value %d is in the tree\n", searchPtr->data);
  }

  printf("Enter a search key for deletion: ");
  scanf("%d", &searchKey);
  deleteNode(&rootPtr, searchKey);
  puts("");

  puts("The value in the tree are: ");
  inOrder(rootPtr);
  puts("");
  
}
		
/* search for key in tree */
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, int key)
{
  if (treePtr == NULL)/* implies treePtr is NULL */
    {
      // add code here to process search key not found
      return NULL;
    }				
  else if (key == treePtr->data)/* implies (key == treePtr->data) */
    {
      // add code here to process search key found
      return treePtr;
    }				
  else if (key < treePtr->data)/* implies (key < treePtr->data) */
    {
      // add code here to continue searching left subtree
      binaryTreeSearch(treePtr->leftPtr, key);
    }				
  else   /* implies (key > treePtr->data) */
    {
      // add code here to search right tree
      binaryTreeSearch(treePtr->rightPtr, key);
             
    }				
}				




 /* insert a node into the tree */
void insertNode (TreeNodePtr * treePtr, int value)
{
  /* if treePtr is NULL */
  if (*treePtr == NULL)
    {
      /* dynamically allocate memory */
      *treePtr = malloc (sizeof (TreeNode));

      /* if memory was allocated, insert node */
      if (*treePtr != NULL)
	{
	  (*treePtr)->data = value;
	  (*treePtr)->leftPtr = NULL;
	  (*treePtr)->rightPtr = NULL;
	}			/* end if */
      else
	{
	  printf ("%d not inserted. No memory available.\n", value);
	}			/* end else */
    }				/* end if */
  else
    {				/* recursively call insertNode */
      /* insert node in left subtree */
      if (value < (*treePtr)->data)
	{
	  insertNode (&((*treePtr)->leftPtr), value);
	}			/* end if */
      else
	{
	  /* insert node in right subtree */
	  if (value > (*treePtr)->data)
	    {
	      insertNode (&((*treePtr)->rightPtr), value);
	    }			/* end if */
	  else
	    {			/* duplicate value */
	      printf ("dup");
	    }			/* end else */
	}			/* end else */
    }				/* end else */
}				/* end function insertNode */


void inOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("%d ", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}


// ---------------------- DELETE NODE ----------------------



/* deletes a node from the binary search tree */
void deleteNode( TreeNodePtr *treePtr, int value )
{
    int found ;
    TreeNodePtr parentPtr, tempNodePtr, replacementNodePtr ;
    
    /* if tree is empty */
    if ( *treePtr == NULL )
    {
        printf ( "\nTree is empty" ) ;
        return ;
    }

    parentPtr = NULL ;
    tempNodePtr = NULL;

    /* find the node to be deleted */
    searchNode ( treePtr, value, &parentPtr, &tempNodePtr, &found ) ;

    /* if the node is not found */
    if ( found == FALSE )
    {
        printf ( "\n Data not found" ) ;
        return ;
    }

    /* if the node to be deleted has two children */
    if ( tempNodePtr -> leftPtr != NULL && tempNodePtr -> rightPtr != NULL )
    {
        parentPtr = tempNodePtr ;
        replacementNodePtr = tempNodePtr -> rightPtr ;

        while ( replacementNodePtr -> leftPtr != NULL )
        {
            parentPtr = replacementNodePtr ;
            replacementNodePtr = replacementNodePtr -> leftPtr ;
        }

        tempNodePtr -> data = replacementNodePtr -> data ;
        tempNodePtr = replacementNodePtr ;
    }

    /* if the node to be deleted has no child */
    if ( tempNodePtr -> leftPtr == NULL && tempNodePtr -> rightPtr == NULL )
    {
        if ( parentPtr -> rightPtr == tempNodePtr )
            parentPtr -> rightPtr = NULL ;
        else
            parentPtr -> leftPtr = NULL ;

        free ( tempNodePtr ) ;
        return ;
    }

    /* if the node to be deleted has only rightPtr */
   if ( tempNodePtr -> leftPtr == NULL && tempNodePtr -> rightPtr != NULL )
    {
        if ( parentPtr -> leftPtr == tempNodePtr )
            parentPtr -> leftPtr = tempNodePtr -> rightPtr ;
        else
            parentPtr -> rightPtr = tempNodePtr -> rightPtr ;

        free ( tempNodePtr ) ;
        return ;
    }

    /* if the node to be deleted has only left child */
    if ( tempNodePtr -> leftPtr != NULL && tempNodePtr -> rightPtr == NULL )
    {
        if ( parentPtr -> leftPtr == tempNodePtr )
            parentPtr -> leftPtr = tempNodePtr -> leftPtr ;
        else
            parentPtr -> rightPtr = tempNodePtr -> leftPtr ;

        free ( tempNodePtr ) ;
        return ;
    }
}

void searchNode ( TreeNodePtr *treePtr, int value, TreeNodePtr *parentPtr, TreeNodePtr *tempNodePtr, int *found )
{
    TreeNodePtr tempPtr ;
    tempPtr = *treePtr ;
    *found = FALSE ;
    *parentPtr = NULL ;

    while ( tempPtr != NULL )
    {
     if ( tempPtr -> data == value )
     {
       *found = TRUE ;
       *tempNodePtr = tempPtr ;
       return ;
     }

       *parentPtr = tempPtr ;
        if ( tempPtr -> data > value )
            tempPtr = tempPtr -> leftPtr ;
        else
            tempPtr = tempPtr -> rightPtr ;
    }
}


