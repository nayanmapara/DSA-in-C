// demonstrate passing arrays to functions
#include<stdio.h>
#include<stdlib.h>
#define N 3

//Function prototypes
void get_matrix(int matrix1[N][N], int matrix2[N][N]);
void sum_matrix(int matrix1[N][N], int matrix2[N][N], int result[N][N]);
void print_matrix(int matrix1[N][N], int matrix2[N][N], int result[N][N]);


int main() 
{
   int matrix1[N][N]={{0},{0},{0}}; // declaring & initialising arrays
   int matrix2[N][N]={{0},{0},{0}};
   int result[N][N]={{0},{0},{0}};

   get_matrix(matrix1, matrix2);	// function calls passing arrays as arguments
   sum_matrix(matrix1, matrix2, result);// note: arrays being passed by address
   print_matrix(matrix1, matrix2, result);
 
}

/**********Function Definitions*************/

void get_matrix(int matrix1[N][N], int matrix2[N][N])
{
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
}

void sum_matrix(int matrix1[N][N], int matrix2[N][N], int result[N][N])
{
   size_t row, col;
  for(row=0; row<N; row++){
      for (col=0; col<N; col++){
            result[row][col] = matrix1[row][col]+matrix2[row][col];
      }
   }
}

void print_matrix(int matrix1[N][N], int matrix2[N][N], int result[N][N])
{
   size_t row, col;
 puts("Matrix-1 Using Functions");
   for(row=0; row<N; row++){
           for(col=0; col<N; col++){
                printf("%d\t",matrix1[row][col]);
       }
       puts("");
   }
   puts("");
   puts("Matrix-2 Using Functions");
   for(row=0; row<N; row++){
           for(col=0; col<N; col++){
                printf("%d\t",matrix2[row][col]);
       }
       puts("");
   }
   puts("");
   puts("Result Matrix Using Functions");
   for(row=0; row<N; row++){
           for(col=0; col<N; col++){
                printf("%d\t",result[row][col]);
       }
       puts("");
   }
   puts(""); 
}




