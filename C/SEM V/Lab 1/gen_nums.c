// 1. Implement recursive linear and binary search and determine the time taken
// to search an element. Repeat the experiment for different values of n, the
// number of elements in the list to be searched and plot a graph of the time
// taken versus n

// Included Libraries
#include <limits.h>  // Maximum value of int (constant)
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Random number generation
#include <time.h>    // Time based operations

// Macro definitions
#define MAX_LENGTH   20         // Array length
#define MAX_NUM      USHRT_MAX  // Maximum element in array
#define ITERATIONS   20000      // Maximum number of searches
#define NOT_FOUND    -1         // Element not found in array
#define LINEAR_INDEX 1  // Command line argument index for linear search file
#define BINARY_INDEX 2  // Command line argument index for binary search file

// Function definitions
void gen_rand_arr(int*, int);  // Generates random array
void print_arr(int*, int);     // Prints array
void sort_arr(int*, int);      // Sorts array in increasing order
int  random_query(int*, int);  // Gets a random element from array
int  linear_search(int*, int, int, int, int*);       // Recursive linear search
int  binary_search(int*, int, int, int, int, int*);  // Recursive binary search

int
main(int argc, char** argv) {
    int   array[MAX_LENGTH];  // Array in use in the program
    int   len = MAX_LENGTH;   // Length of array
    int   query;              // Element to be searched for
    int   index_found_at;     // Index location of element
    int   steps;              // Steps taken to find element
    FILE* linear_file;  // Text file to store steps taken in linear searching
    FILE* binary_file;  // Text file to store steps taken in binary searching

    srand(time(NULL));  // Takes current time as seed for rand()

    gen_rand_arr(array,
                 len);     // Generates an array of random integers `len` long
    sort_arr(array, len);  // Sorts an array `length` long in increasing order

    linear_file = fopen(argv[LINEAR_INDEX],
                        "w");  // Opens file to store linear search steps
    binary_file = fopen(argv[BINARY_INDEX],
                        "w");  // Opens file to store binary search steps

    for ( int i = 0; i < ITERATIONS; i++ ) {
        int lin_steps = 0;  // Steps taken to linear search `iter` times
        int bin_steps = 0;  // Steps taken to binary search `iter` times
        int iter      = 0;  // Number of searches in each iteration

        while ( iter <= i ) {
            query = random_query(array, len);

            steps          = 0;
            index_found_at = linear_search(array, len, query, 0, &steps);
            lin_steps += steps;

            steps = 0;
            index_found_at =
                binary_search(array, len, query, 0, len - 1, &steps);
            bin_steps += steps;

            iter++;
        }

        if ( iter % 1000 == 0 ) {
            // Prints number of iterations, number of linear and number of
            // binary steps every 1000 iterations
            fprintf(stdout, "iter: %7d, lin: %7d, bin: %7d\n", iter, lin_steps,
                    bin_steps);
        }

        // Adds number of steps in iteration to file
        fprintf(linear_file, "%d ", lin_steps);
        fprintf(binary_file, "%d ", bin_steps);
    }

    fclose(linear_file);
    fclose(binary_file);

    return 0;
}

// Adds `len` numbers less than MAX_NUM to array
void
gen_rand_arr(int* array, int len) {
    for ( int i = 0; i < len; i++ ) {
        array[i] = rand() % MAX_NUM;
    }
}

// Prints first `len` elements of array
void
print_arr(int* array, int len) {
    for ( int i = 0; i < len; i++ ) {
        fprintf(stdout, "%d\t", array[i]);
    }

    fprintf(stdout, "\n");
}

// Sorts array in ascending order via bubble sort
void
sort_arr(int* array, int len) {
    int temp;

    for ( int i = 0; i < len - 1; i++ ) {
        for ( int j = 0; j < len - 1; j++ ) {
            if ( array[j] > array[j + 1] ) {  // Swap elements if predecessor is
                                              // greater than successor
                temp         = array[j];
                array[j]     = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Gets a random index from the array and returns element at that index
int
random_query(int* array, int len) {
    int random_index = rand() % len;

    return array[random_index];
}

// Recursively forward linear searches the array for `query`
int
linear_search(int* array, int len, int query, int loc, int* steps) {
    *steps += 1;  // Increment number of steps

    if ( loc >= len ) {  // If location is more than length of array, query does
                         // not exist in array
        return NOT_FOUND;
    } else if ( array[loc] == query ) {  // If location is the same as the
                                         // query, location is returned as index
        return loc;
    }

    return linear_search(array, len, query, loc + 1, steps);
}

// Recursively binary searches a sorted array for 'query'
int
binary_search(int* array, int len, int query, int low, int high, int* steps) {
    *steps += 1;  // Increments number of steps

    if ( low > high ) {  // If higher index is greater than lower index, query
                         // does not exist in array
        return NOT_FOUND;
    }

    int mid = (low + high) / 2;  // Midpoint of current subarray

    if ( array[mid] == query ) {  // If element exists at current midpoint of
                                  // subarray, return the midpoint as index
        return mid;
    }

    if ( array[mid] < query ) {  // If midpoint element is lower than query, use
                                 // the second half of subarray as new subarray
        return binary_search(array, len, query, mid + 1, high, steps);
    } else {  // If midpoint element is lower than query, use the first half of
              // subarray as new subarray
        return binary_search(array, len, query, low, mid - 1, steps);
    }
}
