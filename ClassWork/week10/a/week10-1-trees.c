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
   // printf("Inserting without duplicates: ");
   // for ( i = 1; i <= 10; i++ ) { 
   //    item = rand() % 15;
   //    printf( "%3d", item );
   //    //Insert Node Into Tree;
   //    insertNode( &treePtr, item );
   // } 
   // puts( "" );

   printf("Inserting with duplicates: ");
   for ( i = 1; i <= 10; i++ ) { 
      item = rand() % 15;
      printf( "%3d", item );
      //Insert Node Into Tree;
      insertNodeWithDuplicates( &treePtr, item );
   }
   puts( "" );

   /* traverse the tree preorder */
   puts("Preorder traversal of tree is:");
   preOrder( treePtr );
   puts("");
   
   /* traverse the tree inorder */
   puts("Inorder traversal of tree is:");
   inOrder( treePtr );
   puts("");

   /* traverse the tree inorder */
   puts("InReverseOrder traversal of tree is:");
   inReverseOrder( treePtr );
   puts("");

   /* traverse the tree postorder */
   puts("Postorder traversal of tree is:");
   postOrder( treePtr );
   puts("");
   
} /* end main */
   

