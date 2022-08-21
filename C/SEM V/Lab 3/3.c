// 3. Write a program to implement QuickSort Algorithm

// Included Libraries
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Random number generation
#include <time.h>    // Time based operations

#define MAX_LENGTH   20    // Maximum length of array
#define MAX_ELEM     1000  // Maximum element in array
#define SORT_ARRAY   1     // Menu driven program options
#define RESEED_ARRAY 2     // Menu driven program options
#define EXIT         3     // Menu driven program options

// Macro for swapping elements of array
#define SWAP(TYPE, A, B) \
    TYPE TEMP = A;       \
    A         = B;       \
    B         = TEMP;

// Function Declarations
void gen_rand_arr(int*, const int);     // Generates random array
void print_arr(const int*, const int);  // Prints Array
int  partition(int*,
               const int,
               const int,
               const int,
               int*);  // Partitions array according to pivot
void quick_sort(int*,
                const int,
                const int,
                const int,
                int*);  // Sorts array via QuickSort algorithm

int
main(int argc, char** argv) {
    int       array[MAX_LENGTH];  // Array in use in the program
    const int len = MAX_LENGTH;   // Length of array
    int       pass;               // Number of passes of algorithm
    int       choice;  // Variable used to declare choice in menu driven program

    srand(time(NULL));  // Takes current time as seed for `rand()`

    do {
        pass = 0;  // At start of iteration, number of passes is set to zero

        fprintf(stdout, "\nBase Array:\n");
        gen_rand_arr(array, len);  // Generates an array of random integers
        print_arr(array, len);

        // Menu driven program
        fprintf(stdout, "1. Sort Array\n");
        fprintf(stdout, "2. Reseed Array\n");
        fprintf(stdout, "3. Exit\n");
        fprintf(stdout, "Enter Choice: ");
        fscanf(stdin, "%d", &choice);

        switch ( choice ) {
        case SORT_ARRAY: {
            quick_sort(array, len, 0, len - 1, &pass);

            fprintf(stdout, "Sorted Array:\n");
            print_arr(array, len);
        } break;

        case RESEED_ARRAY: {
            srand(time(NULL));
        } break;

        case EXIT: {
        } break;
        }
    } while ( choice != 3 );

    return 0;
}

// Adds `len` numbers less than MAX_NUM to array
void
gen_rand_arr(int* array, const int len) {
    for ( int i = 0; i < len; i++ ) {
        array[i] = rand() % MAX_ELEM;
    }
}

// Prints first `len` elements of array
void
print_arr(const int* array, const int len) {
    for ( int i = 0; i < len; i++ ) {
        fprintf(stdout, "%4d", array[i]);
    }

    fprintf(stdout, "\n");
}

// Divides array into two subarrays around a pivot, with first subarray being
// elements lower than pivot, and second subarray being elements greater than
// pivot
int
partition(int*      array,
          const int len,
          const int start,
          const int end,
          int*      pass) {
    int pivot_index = end;          // Pivot location
    int i           = (start - 1);  // Running index of elements

    for ( int j = start; j < end; j++ ) {
        if ( array[j] <
             array[pivot_index] ) {  // If element is lower than pivot, it is
                                     // swapped with the running element
            i++;

            SWAP(int, array[i], array[j]);
        }
    }

    SWAP(int, array[i + 1],
         array[end]);  // Swap pivot index to its correct location

    (*pass) += 1;
    fprintf(stdout, "Pass %2d:", *pass);
    print_arr(array, len);

    return i + 1;  // Return location of pivot
}

// Sorts array in ascending order via QuickSort
void
quick_sort(int*      array,
           const int len,
           const int start,
           const int end,
           int*      pass) {
    int index;

    if ( start < end ) {
        index =
            partition(array, len, start, end, pass);  // Gets partition index

        quick_sort(array, len, start, index - 1,
                   pass);  // Sorts subarray lower than pivot
        quick_sort(array, len, index + 1, end,
                   pass);  // Sorts subarray greater than pivot
    }
}
