#include <stdio.h>
#include <stdlib.h>

// Set up our sturcture definition
struct treeNode {
    struct treeNode *leftPtr;
    int data;
    struct treeNode *rightPtr;
};

// Type renaming
typedef struct treeNode TreeNode;
typedef struct treeNode *TreeNodePtr;

// Function prototypes
void insertNode(TreeNodePtr *treePtr, int value);
void insertNodeWithDuplicates(TreeNodePtr *treePtr, int value);
void preOrder(TreeNodePtr treePtr);
void inOrder(TreeNodePtr treePtr);
void inReverseOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);
TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, int key);

void insertNode(TreeNodePtr *treePtr, int value)
{
    if (*treePtr == NULL) // Node can be inserted as a leaf node
    {
        *treePtr = (TreeNodePtr) malloc(sizeof(TreeNode));
        if (*treePtr != NULL)
        {
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->data = value;
            (*treePtr)->rightPtr = NULL;

        } else {
            puts("Memory issues... Node not created.");
        }

        return;

    } else { // otherwise, continue for apporiate place to insert by going left/right
        if (value < (*treePtr)->data)
        {
            //go left
            insertNode(&((*treePtr)->leftPtr), value);

        } else if (value > (*treePtr)->data)
        {
            //go right
            insertNode(&((*treePtr)->rightPtr), value);

        } else {
            //duplicate elimination 
            printf("%s", "-duplicate-not-inserted");
        }
    }
}

void insertNodeWithDuplicates(TreeNodePtr *treePtr, int value)
{
    if (*treePtr == NULL) // Node can be inserted as a leaf node
    {
        *treePtr = (TreeNodePtr) malloc(sizeof(TreeNode));
        if (*treePtr != NULL)
        {
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->data = value;
            (*treePtr)->rightPtr = NULL;

        } else {
            puts("Memory issues... Node not created.");
        }

        return;

    } else { // otherwise, continue for apporiate place to insert by going left/right
        if (value <= (*treePtr)->data)
        {
            //go left
            insertNodeWithDuplicates(&((*treePtr)->leftPtr), value);

        } else
        {
            //go right
            insertNodeWithDuplicates(&((*treePtr)->rightPtr), value);
        } 
    }
}

void preOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        printf("%d ", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void inOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        inOrder(treePtr->leftPtr);
        printf("%d ", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void inReverseOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        inReverseOrder(treePtr->rightPtr);
        printf("%d ", treePtr->data);
        inReverseOrder(treePtr->leftPtr);
    }
}

void postOrder(TreeNodePtr treePtr)
{
    if (treePtr != NULL)
    {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%d ", treePtr->data);
    }
}

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