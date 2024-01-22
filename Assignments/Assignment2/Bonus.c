// demonstrate passing arrays to functions
#include<stdio.h>
#include<stdlib.h>
#define ROW 3
#define COL 3

//Function prototypes
void get_matrix(float matrix1[][COL], float matrix2[][COL]); //COL is mandatory, ROW is not.
void sum_matrix(float matrix1[][COL], float matrix2[][COL], float result[][COL]);
void print_matrix(float matrix1[][COL], float matrix2[][COL], float result[][COL]);


int main() {
    float matrix1[ROW][COL]= {{0},{0},{0}}; // declaring & initialising arrays
    float matrix2[ROW][COL]= {{0},{0},{0}};
    float result[ROW][COL]= {{0},{0},{0}};

    get_matrix(matrix1, matrix2);    // function calls passing arrays as arguments
    multiply_matrix(matrix1, matrix2, result);// note: arrays being passed by address
    print_matrix(matrix1, matrix2, result);

}

/**********Function Definitions*************/

void get_matrix(float matrix1[][COL], float matrix2[][COL]) {
    size_t row, col;
    // read values into matrix-1
    printf("Read values into matrix-1 :");
    for(row=0; row<ROW; row++) {
        for(col=0; col<COL; col++) {
            //printf("Enter value at Row %zu, Col %zu :", row, col);
            scanf("%f", &matrix1[row][col]);
        }
    }
    puts("");

    // read values into matrix-2
    printf("Read values into matrix-2 :");
    for(row=0; row<ROW; row++) {
        for(col=0; col<COL; col++) {
            //printf("Enter value at Row %zu, Col %zu :", row, col);
            scanf("%f", &matrix2[row][col]);
        }
    }
    puts("");
}

void sum_matrix(float matrix1[][COL], float matrix2[][COL], float result[][COL]) {
    size_t row, col;
    for(row=0; row<ROW; row++) {
        for(col=0; col<COL; col++) {
            result[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }
}

void multiply_matrix(float matrix1[][COL], float matrix2[][COL], float result[][COL]) {
    size_t row, col;
    for(row=0; row<ROW; row++) {
        for(col=0; col<COL; col++) {
            result[row][col] = ((matrix1[row][0] * matrix2[0][col]) + (matrix1[row][1] * matrix2[1][col]) + (matrix1[row][2] * matrix2[2][col]) );
        }
    }
}

void print_matrix(float matrix1[][COL], float matrix2[][COL], float result[][COL]) {
    size_t row, col;


    puts("The multiplication of the matrices is");
    for(col=0; col<COL; col++) {
        printf("%.1f ",matrix1[0][col]);
    }
    printf("\t");
    for(col=0; col<COL; col++) {
        printf("%.1f ",matrix2[0][col]);
    }
    printf("\t");
    for(col=0; col<COL; col++) {
        printf("%.1f ",result[0][col]);
    }
    printf("\n");
    
    for(col=0; col<COL; col++) {
        printf("%.1f ",matrix1[1][col]);
    }
    printf(" *  ");
    for(col=0; col<COL; col++) {
        printf("%.1f ",matrix2[1][col]);
    }
    printf(" =  ");
    for(col=0; col<COL; col++) {
        printf("%.1f ",result[1][col]);
    }
    printf("\n");
    
    for(col=0; col<COL; col++) {
        printf("%.1f ",matrix1[2][col]);
    }
    printf("\t");
    for(col=0; col<COL; col++) {
        printf("%.1f ",matrix2[2][col]);
    }
    printf("\t");
    for(col=0; col<COL; col++) {
        printf("%.1f ",result[2][col]);
    }
    printf("\n");
}