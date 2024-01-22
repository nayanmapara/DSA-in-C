// Write a program that performs matrix addition on two N x N matrices
#include <stdio.h>
#define N 3

int main( void )
{
   // declare and initialise matrices
   int matrix1[N][N]={0};
   int matrix2[N][N]={0};
   int resultMatrix[N][N]={0};
   size_t row, col;
   
   puts("Read values into matrix-1");
   for(row=0; row<N; row++){
      for (col=0; col<N; col++){
            printf("Enter Value at Row %Zu Col %Zu: ", row, col);
            scanf("%d", &matrix1[row][col]);
      }
   }

   puts("Read values into matrix-2");
   for(row=0; row<N; row++){
      for (col=0; col<N; col++){
            printf("Enter Value at Row %Zu Col %Zu: ", row, col);
            scanf("%d", &matrix2[row][col]);
      }
   }
   puts("");
      
   // compute and load values into result matrix
   for(row=0; row<N; row++){
      for (col=0; col<N; col++){
            resultMatrix[row][col] = matrix1[row][col]+matrix2[row][col];
      }
   }
   
   // output matrix-1, matrix-2 and result-matrix
   puts("Matrix-1");
   for(row=0; row<N; row++){
           for(col=0; col<N; col++){
                printf("%d\t",matrix1[row][col]);
       }
       puts("");
   }
   puts("");
   puts("Matrix-2");
   for(row=0; row<N; row++){
           for(col=0; col<N; col++){
                printf("%d\t",matrix2[row][col]);
       }
       puts("");
   }
   puts("");
   puts("Result Matrix");
   for(row=0; row<N; row++){
           for(col=0; col<N; col++){
                printf("%d\t",resultMatrix[row][col]);
       }
       puts("");
   }
   puts("");
   
} 


