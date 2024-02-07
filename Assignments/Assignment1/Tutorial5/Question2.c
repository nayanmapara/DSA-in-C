// Name: Nayan
// Question: 6.22 Total Sales

#include <stdio.h>

#define NUM_SALESPERSON 4
#define NUM_PRODUCTS 5

void printTable(double sales[NUM_PRODUCTS][NUM_SALESPERSON]);

int main() {
    double sales[NUM_PRODUCTS][NUM_SALESPERSON] = {0.0};

    // Read sales information for last month
    for (int i = 0; i < NUM_SALESPERSON; ++i) {
        for (int j = 0; j < NUM_PRODUCTS; ++j) {
            printf("Enter total sales for Salesperson %d and Product %d: ", i + 1, j + 1);
            scanf("%lf", &sales[j][i]);
        }
    }

    printTable(sales);

    return 0;
}

void printTable(double sales[NUM_PRODUCTS][NUM_SALESPERSON]) {
    printf("Product\\Salesperson\t");
    for (int i = 0; i < NUM_SALESPERSON; ++i) {
        printf("Salesperson %d\t", i + 1);
    }
    printf("\tTotal\n");

    double totalSales[NUM_PRODUCTS] = {0.0};
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        printf("Product %d\t\t\t", i + 1);
        double rowTotal = 0.0;
        for (int j = 0; j < NUM_SALESPERSON; ++j) {
            printf("$%.2lf\t\t", sales[i][j]);
            rowTotal += sales[i][j];
            totalSales[i] += sales[i][j];
        }
        printf("$%.2lf\n", rowTotal);
    }

    printf("Grand Total:\t");
    double grandTotal = 0.0;
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        grandTotal += totalSales[i];
    }

    printf("$%.2lf\n", grandTotal);
}