// Write a program to solve the Zero-One Knapsack Problem using Dynamic
// Programming Approach

// Included Libraries
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Memory operations

// Macro Definitions
#define ITEM_COUNT_STR   argv[1]  // Command line argument for number of items
#define BAG_CAPACITY_STR argv[2]  // Command line argument for bag capacity
#define PRINT_LINE(COLS)                   \
    fprintf(stdout, "\n+");                \
    for ( int i = 0; i < cols * 5; i++ ) { \
        if ( (i + 1) % 5 == 0 ) {          \
            fprintf(stdout, "+");          \
        } else {                           \
            fprintf(stdout, "-");          \
        }                                  \
    }                                      \
    fprintf(stdout, "\n");

/** @brief Structure to model a Knapsack problem item */
struct Item {
    int name;    // Name of the item
    int weight;  // Weight of the item
    int value;   // Total value of the item
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
void  print_matrix(struct Solution** solution, int const rows, int const cols);
/**
 * @brief Print a summary table for the @p items
 * @param items Array of items
 * @param len Number of @p items
 */
void  print_items(struct Item* items, int len);
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
    // If no items or bag capacity are mentioned, skip execution of program
    if ( ! ITEM_COUNT_STR || ! BAG_CAPACITY_STR || argc != 3 ) {
        return 0;
    }

    int len      = atoi(ITEM_COUNT_STR);
    int capacity = atoi(BAG_CAPACITY_STR);

    struct Item items[] = {
        {.name = 1, .weight = 5, .value = 10},
        {.name = 2, .weight = 4, .value = 40},
        {.name = 3, .weight = 6, .value = 40},
        {.name = 4, .weight = 3, .value = 50}
    };

    // struct Item items[] = {
    //     {.name = 1, .weight = 1,  .value = 1, .price = 0.0f},
    //     {.name = 2, .weight = 2,  .value = 6, .price = 0.0f},
    //     {.name = 3, .weight = 5, .value = 18, .price = 0.0f},
    //     {.name = 4, .weight = 6, .value = 22, .price = 0.0f},
    //     {.name = 5, .weight = 7, .value = 28, .price = 0.0f}
    // };

    fprintf(stdout, "Given Items:\n");

    print_items(items, len);

    fprintf(stdout, "\n");

    fprintf(stdout, "\nTotal Profit Earned: %.2f",
            zero_one_knapsack(items, len, capacity));

    return 0;
}

void
print_matrix(struct Solution** solution, int rows, int cols) {
    fprintf(stdout, "C Matrix:");

    PRINT_LINE(cols);

    for ( int i = 0; i < rows; i++ ) {
        fprintf(stdout, "|");

        for ( int j = 0; j < cols; j++ ) {
            if ( solution[i][j].C == -1 ) {
                fprintf(stdout, "    |");
            } else {
                fprintf(stdout, " %2d |", solution[i][j].C);
            }
        }

        PRINT_LINE(cols);
    }

    fprintf(stdout, "\nKeep Matrix:");

    PRINT_LINE(cols);

    for ( int i = 0; i < rows; i++ ) {
        fprintf(stdout, "|");

        for ( int j = 0; j < cols; j++ ) {
            if ( solution[i][j].keep == -1 ) {
                fprintf(stdout, "    |");
            } else {
                fprintf(stdout, " %2d |", solution[i][j].keep);
            }
        }

        PRINT_LINE(cols);
    }

    fprintf(stdout, "\n");
}

void
print_items(struct Item* items, int len) {
    fprintf(stdout, "+------+--------+-------+\n");
    fprintf(stdout, "| Item | Weight | Value |\n");
    fprintf(stdout, "+------+--------+-------+\n");

    for ( int i = 0; i < len; i++ ) {
        fprintf(stdout, "| %3d  |  %3d   |  %3d  |\n", items[i].name,
                items[i].weight, items[i].value);
    }

    fprintf(stdout, "+------+--------+-------+\n");
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
        fprintf(stdout,
                "Item under consideration:\nName: %2d, Value: %2d, Weight: "
                "%2d\n",
                items[i - 1].name, items[i - 1].value, items[i - 1].weight);
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

    fprintf(stdout, "Items kept in knapsack: ");

    for ( int i = len; i >= 1; i-- ) {
        if ( solution[i][k].keep == 1 ) {
            fprintf(stdout, "%d ", i);
            k = k - items[i - 1].weight;
        }
    }

    return solution[len][capacity].C;
}