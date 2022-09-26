// Write a program to solve the Zero-One Knapsack Problem using Dynamic
// Programming Approach

// Included Libraries
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Memory operations

/** @brief Structure to model a Knapsack problem item */
struct Item {
    unsigned int name;    // Name of the item
    unsigned int weight;  // Weight of the item
    unsigned int value;   // Total value of the item
    float        price;   // Price of the value per unit weight
};

/** @brief Structure containing solution matrices for the execution */
struct Solution {
    int C;  // Contains maximum value of any of the subset of items {1, 2, ...,
            // i} of at most capacity
    int keep;  // Contains information of which items are kept in the knapsack
};

/**
 * @brief Prints given matrix of @p solution of `struct Solution` type
 * @param solution Given matrix
 * @param rows Number of rows in @p solution
 * @param cols Number of columns in @p solution
 */
void print_matrix(struct Solution** solution, int const rows, int const cols);

/**
 * @brief Solves the Zero-One Knapsack Problem via Dynamic Programming approach
 * on the @p items array
 * @param items Array of items
 * @param len Number of @p items
 * @param capacity Total capacity of the bag
 * @return Maximum profit achievable from the @p items array
 */
float zero_one_knapsack(struct Item* items, int len, int capacity);

int
main(int argc, char** argv) {
    int len      = 4;
    int capacity = 10;

    struct Item items[] = {
        {.name = 1, .weight = 5, .value = 10, .price = 0.0f},
        {.name = 2, .weight = 4, .value = 40, .price = 0.0f},
        {.name = 3, .weight = 6, .value = 40, .price = 0.0f},
        {.name = 4, .weight = 3, .value = 50, .price = 0.0f}
    };

    fprintf(stdout, "%.2f", zero_one_knapsack(items, len, capacity));

    return 0;
}

void
print_matrix(struct Solution** solution, int rows, int cols) {
    fprintf(stdout, "C\n");

    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < cols; j++ ) {
            if ( solution[i][j].C == -1 ) {
                fprintf(stdout, "    ");
            } else {
                fprintf(stdout, "%2d ", solution[i][j].C);
            }
        }

        fprintf(stdout, "\n");
    }

    fprintf(stdout, "Keep\n");

    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < cols; j++ ) {
            if ( solution[i][j].keep == -1 ) {
                fprintf(stdout, "    ");
            } else {
                fprintf(stdout, "%2d ", solution[i][j].keep);
            }
        }

        fprintf(stdout, "\n");
    }

    fprintf(stdout, "\n");
}

float
zero_one_knapsack(struct Item* items, int len, int capacity) {
    struct Solution** solution =
        ( struct Solution** ) malloc((len + 1) * sizeof(struct Solution*));

    for ( int i = 0; i < (len + 1); i++ ) {
        solution[i] = ( struct Solution* ) malloc((capacity + 1) *
                                                  sizeof(struct Solution));
    }

    for ( int i = 0; i < (len + 1); i++ ) {
        for ( int j = 0; j < (capacity + 1); j++ ) {
            if ( i == 0 || j == 0 ) {
                solution[i][j].C    = 0;
                solution[i][j].keep = 0;
            } else {
                solution[i][j].C    = -1;
                solution[i][j].keep = -1;
            }
        }
    }

    print_matrix(solution, len + 1, capacity + 1);

    for ( int i = 1; i < (len + 1); i++ ) {
        for ( int j = 1; j < (capacity + 1); j++ ) {
            if ( (items[i - 1].weight <= j) &&
                 (items[i - 1].value +
                      solution[i - 1][j - items[i - 1].weight].C >
                  solution[i - 1][j].C) ) {
                solution[i][j].C = items[i - 1].value +
                                   solution[i - 1][j - items[i - 1].weight].C;
                solution[i][j].keep = 1;
            } else {
                solution[i][j].C    = solution[i - 1][j].C;
                solution[i][j].keep = 0;
            }
        }

        print_matrix(solution, len + 1, capacity + 1);
    }

    int k = capacity;

    for ( int i = len; i >= 1; i-- ) {
        if ( solution[i][k].keep == 1 ) {
            fprintf(stdout, "%d ", i);
            k = k - items[i - 1].weight;
        }
    }

    return solution[len][capacity].C;
}