// 2. Write a program to implement Selection, Bubble and Insertion Sorting
// Algorithms

// Included Libraries
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Random number generation
#include <time.h>    // Time based operations

// Macro definitions
#define MAX_LENGTH     20   // Maximum length of array
#define MAX_ELEM       100  // Maximum element in array
#define BUBBLE_SORT    1    // Menu driven program options
#define SELECTION_SORT 2    // Menu driven program options
#define INSERTION_SORT 3    // Menu driven program options
#define RESEED_ARRAY   4    // Menu driven program options
#define EXIT           5    // Menu driven program options

// Macro for swapping elements of array
#define SWAP(TYPE, A, B) \
    TYPE temp = A;       \
    A         = B;       \
    B         = temp;

// Function declarations
void gen_rand_arr(int*, int);    // Generates random array
void print_arr(int*, int);       // Prints array
void selection_sort(int*, int);  // Sorts array via selection sort algorithm
void bubble_sort(int*, int);     // Sorts array via bubble sort algorithm
void insertion_sort(int*, int);  // Sorts array via insertion sort algorithm

int
main(int argc, char** argv) {
    int choice;  // Variable used to declare choice in menu driven program

    srand(time(NULL));  // Takes current time as seed for rand()

    do {
        int array[MAX_LENGTH];  // Array in use in the program
        int len = MAX_LENGTH;   // Length of array

        gen_rand_arr(array,
                     len);  // Generates an array of random integers `len` long
        fprintf(stdout, "Base Array:\n");
        print_arr(array, len);

        // Menu driven program
        fprintf(stdout, "1. Bubble Sort\n");
        fprintf(stdout, "2. Selection Sort\n");
        fprintf(stdout, "3. Insertion Sort\n");
        fprintf(stdout, "4. Reseed Array\n");
        fprintf(stdout, "5. Exit\n");
        fprintf(stdout, "Enter Choice: ");
        fscanf(stdin, "%d", &choice);

        switch ( choice ) {
        case BUBBLE_SORT: {
            bubble_sort(array, len);
        } break;

        case SELECTION_SORT: {
            selection_sort(array, len);
        } break;

        case INSERTION_SORT: {
            insertion_sort(array, len);
        } break;

        case RESEED_ARRAY: {
            srand(time(NULL));
        } break;

        case EXIT: {
        } break;

        default: {
        } break;
        }
    } while ( choice != 5 );

    return 0;
}

// Adds `len` numbers less than MAX_NUM to array
void
gen_rand_arr(int* array, int len) {
    for ( int i = 0; i < len; i++ ) {
        array[i] = rand() % MAX_ELEM;
    }
}

// Prints first `len` elements of array
void
print_arr(int* array, int len) {
    for ( int i = 0; i < len; i++ ) {
        fprintf(stdout, "%3d ", array[i]);
    }

    fprintf(stdout, "\n");
}

// Sorts array in ascending order via selection sort
void
selection_sort(int* array, int len) {
    int min_index;  // Index of minimum element of array

    for ( int i = 0; i < len - 1; i++ ) {
        min_index = i;  // Initialize minimum element as first element of array

        for ( int j = i + 1; j < len; j++ ) {
            if ( array[j] < array[min_index] ) {
                min_index = j;  // Change index if smaller element is found
            }
        }

        SWAP(int, array[min_index],
             array[i]);  // Swap first element with lowest element

        fprintf(stdout, "Pass %3d: ", (i + 1));
        print_arr(array, len);
    }
}

// Sorts array in ascending order via bubble sort
void
bubble_sort(int* array, int len) {
    for ( int i = 0; i < len; i++ ) {
        for ( int j = 0; j < len - i; j++ ) {
            if ( array[j] >
                 array[j + 1] ) {  // Find if element is larger than successor
                SWAP(int, array[j],
                     array[j + 1]);  // Swaps elements to be in order one-by-one
            }
        }

        fprintf(stdout, "Pass %3d: ", (i + 1));
        print_arr(array, len);
    }
}

// Sorts array in ascending order via insertion sort algorithm
void
insertion_sort(int* array, int len) {
    int element;

    for ( int i = 1; i < len; i++ ) {
        element = array[i];  // Element being examined

        for ( int j = i; j > 0; j-- ) {
            if ( array[j - 1] >
                 array[j] ) {  // If element is larger than successor
                SWAP(int, array[j - 1], array[j]);  // Swaps elements to get to
                                                    // their correct position
            }
        }

        fprintf(stdout, "Pass %3d: ", (i + 1));
        print_arr(array, len);
    }
}