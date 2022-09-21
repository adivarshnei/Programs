// 5. Write a program to solve the Fractional Knapsack problem using Greedy
// Approach.

// Included Libraries
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Memory operations and atoi()

// Macro Definitions
#define ITEM_COUNT_STR   argv[1]  // Command line argument for number of items
#define BAG_CAPACITY_STR argv[2]  // Command line argument for bag capacity
/**
 * @brief Macro to Swap @p A and @p B
 * @param A First Item
 * @param B Second Item
 */
#define ITEMSWAP(A, B)    \
    struct Item temp = A; \
    A                = B; \
    B                = temp;

/** @brief Structure to model a Knapsack problem item */
struct Item {
    int   name;    // Name of the item
    int   weight;  // Weight of the item
    int   value;   // Total value of the item
    float price;   // Price of the value per unit weight
};

/** @brief Structure to model an Item in a Bag */
struct Item_In_Bag {
    struct Item item;           // Item details
    int         weight_in_bag;  // Weight of the item stored in bag
};

/**
 * @brief Print a summary table for the @p items
 * @param items Array of items
 * @param len Number of @p items
 * @param print_prices Whether to print prices or not. Takes values 1 (Print
 * prices of each item) or 0 (Do not print prices of each item)
 * @param in_bag Whether the item is in the bad or not. Used only if @p
 * print_prices is 1. Takes values 1 (Print amount of each item in the bag) or 0
 * (Do not print amount of each item in the bag)
 * @param amounts_in_bag Amount of @p items in the bag. Works only if @p in_bag
 * is 1.
 */
void  print_items(struct Item* items,
                  int          len,
                  int          print_prices,
                  int          in_bag,
                  int*         amounts_in_bag);
/**
 * @brief Sort the @p items by their respective prices in decreasing order via
 * bubble sort
 * @param items Array of items
 * @param len Number of @p items
 */
void  sort_items(struct Item* items, int len);
/**
 * @brief Solves the Fractional Knapsack Problem via greedy approach on the @p
 * items array
 * @param items Array of items
 * @param len Number of @p items
 * @param capacity Total capacity of the bag
 * @return Maximum profit achievable from the @p items array
 */
float fractional_knapsack(struct Item* items, int len, int capacity);

int
main(int argc, char** argv) {
    // If no items or bag capacity are mentioned, skip execution of program
    if ( ! ITEM_COUNT_STR || ! BAG_CAPACITY_STR ) {
        return 0;
    }

    // Initialize items
    struct Item items[] = {
        {.name = 1,  .weight = 5,  .value = 30, .price = 0.0},
        {.name = 2, .weight = 10,  .value = 20, .price = 0.0},
        {.name = 3, .weight = 20, .value = 100, .price = 0.0},
        {.name = 4, .weight = 30,  .value = 90, .price = 0.0},
        {.name = 5, .weight = 40, .value = 160, .price = 0.0}
    };

    fprintf(stdout, "Items Given:\n");
    print_items(items, atoi(ITEM_COUNT_STR), 0, 0, NULL);

    fprintf(stdout, "Bag Capactiy: %d\n", atoi(BAG_CAPACITY_STR));

    // Get the maximum profit possible from the list of items by solving the
    // Fractional Knapsack Problem
    fprintf(stdout, "Total Profit Accumulated: %.2f",
            fractional_knapsack(items, atoi(ITEM_COUNT_STR),
                                atoi(BAG_CAPACITY_STR)));

    return 0;
}

void
print_items(struct Item* items,
            int          len,
            int          print_prices,
            int          in_bag,
            int*         amounts_in_bag) {
    if ( ! print_prices ) {
        fprintf(stdout, "+------+--------+-------+\n");
        fprintf(stdout, "| Item | Weight | Value |\n");
        fprintf(stdout, "+------+--------+-------+\n");

        for ( int i = 0; i < len; i++ ) {
            fprintf(stdout, "| %3d  |  %3d   |  %3d  |\n", items[i].name,
                    items[i].weight, items[i].value);
        }

        fprintf(stdout, "+------+--------+-------+\n");
    } else if ( ! in_bag ) {
        fprintf(stdout, "+------+--------+-------+-------+\n");
        fprintf(stdout, "| Item | Weight | Value | Price |\n");
        fprintf(stdout, "+------+--------+-------+-------+\n");

        for ( int i = 0; i < len; i++ ) {
            fprintf(stdout, "| %3d  |  %3d   |  %3d  |  %2.2f |\n",
                    items[i].name, items[i].weight, items[i].value,
                    items[i].price);
        }

        fprintf(stdout, "+------+--------+-------+-------+\n");
    } else {
        fprintf(
            stdout,
            "+------+--------+-------+-------+---------------+--------------"
            "-------+\n");
        fprintf(stdout,
                "| Item | Weight | Value | Price | Weight In Bag |  Profit "
                "Accumulated |\n");
        fprintf(
            stdout,
            "+------+--------+-------+-------+---------------+--------------"
            "-------+\n");

        for ( int i = 0; i < len; i++ ) {
            int j;

            for ( j = 0; j < len; j++ ) {
                if ( j + 1 == items[i].name ) {
                    break;
                }
            }
            fprintf(stdout,
                    "| %3d  |  %3d   |  %3d  |  %3.2f |      %3d      |        "
                    "%6.2f       |\n",
                    items[i].name, items[i].weight, items[i].value,
                    items[i].price, amounts_in_bag[j],
                    items[i].price * amounts_in_bag[j]);
        }

        fprintf(
            stdout,
            "+------+--------+-------+-------+---------------+--------------"
            "-------+\n");
    }
}

void
sort_items(struct Item* items, int len) {
    for ( int i = 0; i < len; i++ ) {
        for ( int j = 0; j < len - i - 1; j++ ) {
            if ( items[j].price < items[j + 1].price ) {
                ITEMSWAP(items[j], items[j + 1]);
            }
        }
    }
}

float
fractional_knapsack(struct Item* items, int len, int capacity) {
    // Initialise array of items in the bag and the profit
    struct Item_In_Bag* items_in_bag = NULL;
    float               profit       = 0;

    // Get prices per unit weight for each item
    for ( int i = 0; i < len; i++ ) {
        items[i].price = ( float ) items[i].value / ( float ) items[i].weight;
    }

    sort_items(items, len);

    fprintf(stdout, "Items after sorting:\n");
    print_items(items, len, 1, 0, NULL);

    int i = 0;

    int base_capacity = capacity;

    // Iterate through the array of items until the bag has no capacity left. In
    // each iteration, add as much as possible of the maximum price item to the
    // bag and update the profit accordingly.
    while ( capacity > 0 ) {
        fprintf(stdout, "Capacity left in bag: %d\n", capacity);
        fprintf(stdout,
                "Item being Considered: (Name: %3d, Weight: %3d, Value: %3d, "
                "Price: %3.2f)\n",
                items[i].name, items[i].weight, items[i].value, items[i].price);

        int amount = (capacity < items[i].weight) ? capacity : items[i].weight;

        if ( amount == items[i].weight ) {
            fprintf(stdout, "Item Completely Placed in bag\n");
        } else {
            fprintf(stdout, "%d / %d fraction of item placed in bag\n", amount,
                    items[i].weight);
        }

        items_in_bag = ( struct Item_In_Bag* ) realloc(
            items_in_bag, (i + 1) * sizeof(struct Item_In_Bag));

        items_in_bag[i].item          = items[i];
        items_in_bag[i].weight_in_bag = amount;

        capacity -= amount;

        profit += amount * items[i].price;

        fprintf(stdout, "Total profit accumulated so far: %.2f + %.2f = %.2f\n",
                profit - items[i].price * amount, items[i].price * amount,
                profit);

        i++;

        if ( i >= len ) {
            break;
        }

        fprintf(stdout, "\n");
    }

    fprintf(stdout, "Capacity left in bag: %d\n\n", capacity);

    fprintf(stdout, "Summary of Items in Bag:\n");

    int* amounts_in_bag = ( int* ) malloc(len * sizeof(int));

    for ( int j = 0; j < len; j++ ) {
        amounts_in_bag[j] = 0;
    }

    for ( int j = 0; j < i; j++ ) {
        amounts_in_bag[items_in_bag[j].item.name - 1] =
            items_in_bag[j].weight_in_bag;
    }

    print_items(items, len, 1, 1, amounts_in_bag);

    fprintf(stdout, "\nKnapsack Diagram:\n");

    int solution_item_count = i;

    for ( int j = 0; j < base_capacity; j++ ) {
        fprintf(stdout, "-");
    }

    fprintf(stdout, "\n");

    for ( int l = 0; l < 3; l++ ) {
        int amount_filled = 0;
        int k             = 0;

        for ( int j = 0; j < base_capacity; j++ ) {
            if ( j == 0 || j == base_capacity - 1 ) {
                fprintf(stdout, "|");
            } else if ( items_in_bag[k].weight_in_bag + amount_filled == j &&
                        k < solution_item_count ) {
                fprintf(stdout, "|");
                amount_filled += items_in_bag[k].weight_in_bag;
                k++;
            } else {
                if ( l == 1 ) {
                    fprintf(stdout, "%d", items_in_bag[k].item.name);
                } else {
                    fprintf(stdout, " ");
                }
            }
        }

        fprintf(stdout, "\n");
    }

    for ( int j = 0; j < base_capacity; j++ ) {
        fprintf(stdout, "-");
    }

    fprintf(stdout, "\n");

    free(amounts_in_bag);

    return profit;
}
