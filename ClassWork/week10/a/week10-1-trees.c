// Binary Tree Example
#include "trees.h"
#include <time.h>

int main( void )
{ 
   int i; /* loop counter */
   int item; /* variable for random value to insert in tree */
   TreeNodePtr treePtr = NULL;
   
   /* Add Code:  Create Pointer to the tree root */

   
   srand( time( NULL ) ); /* randomize */
   printf( "The numbers being placed in the tree are:\n" );

   /* insert random values between 0 and 14 in the tree */
   for ( i = 1; i <= 10; i++ ) { 
      item = rand() % 15;
      printf( "%3d", item );
      //Insert Node Into Tree;
      insertNode( &treePtr, item );
   } 

   /* traverse the tree preorder */
   puts("");
   preOrder( treePtr );
   puts("");
   
   /* traverse the tree inorder */
   inOrder( treePtr );
   puts("");

   /* traverse the tree postorder */
   postOrder( treePtr );
   puts("");
   
} /* end main */
   

