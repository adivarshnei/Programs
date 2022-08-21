// 3-2. Write a program to implement Merge Sort Algorithm

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

// Function declarations
void gen_rand_arr(int*, const int);     // Generates random array
void print_arr(const int*, const int);  // Prints array
void merge_sort(int*,
                const int,
                const int,
                const int,
                int*);  // Sorts array via merge sort algorithm
void merge(int*,
           const int,
           const int,
           const int,
           int*);  // Merges sorted subarrays

int
main(int argc, char** argv) {
    int       array[MAX_LENGTH];  // Array in use in the program
    const int len = MAX_LENGTH;   // Length of array
    int       pass;               // Number of passes of algorithm
    int       choice;  // Variable used to declare choice in menu driven program

    srand(time(NULL));

    do {
        pass = 0;  // At the start of iteration, number of passes is set to zero

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
            merge_sort(array, len, 0, len - 1, &pass);

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

// Successively subdivides array into subarrays half the size of the previous,
// until the subarray is one element long. After this, subarrays are
// successively merged in a sorted manner, giving the sorted array.
void
merge_sort(int*      array,
           const int len,
           const int start,
           const int end,
           int*      pass) {
    if ( start < end ) {
        int mid = (start + end) / 2;  // Gets middle element of subarray

        merge_sort(
            array, len, start, mid,
            pass);  // Executes merge sort algorithm on subarray before middle
        merge_sort(
            array, len, mid + 1, end,
            pass);  // Executes merge sort algorithm on subarray after middle
        merge(array, start, mid, end,
              pass);  // Merges sorted subarray to form larger array

        (*pass) += 1;

        fprintf(stdout, "Pass %3d: ", *pass);
        print_arr(array, len);
    }
}

// Merges subarrays in a sorted manner
void
merge(int* array, const int start, const int mid, const int end, int* pass) {
    int left_len  = mid - start + 1;  // Length of left subarray
    int right_len = end - mid;        // Length of right subarray

    int* left_arr;   // Left subarray
    int* right_arr;  // Right subarray

    left_arr  = ( int* ) (malloc(
         (left_len) * sizeof(int)));  // Allocates memory for the left subarray
    right_arr = ( int* ) (malloc(
        (right_len) * sizeof(int)));  // Allocates memory for the right subarray

    // Populating left subarray
    for ( int i = 0; i < left_len; i++ ) {
        left_arr[i] = array[start + i];
    }

    // Populating right subarray
    for ( int i = 0; i < right_len; i++ ) {
        right_arr[i] = array[mid + i + 1];
    }

    int left_index  = 0;  // Running index of left array elements
    int right_index = 0;  // Running index of right array elements

    // Loop which generates array with left and right subarray elements arranged
    // in a sorted manner
    for ( int i = start; i < end + 1; i++ ) {
        if ( left_index < left_len && right_index < right_len ) {
            if ( left_arr[left_index] <= right_arr[right_index] ) {
                array[i] = left_arr[left_index++];
            } else if ( left_arr[left_index] > right_arr[right_index] ) {
                array[i] = right_arr[right_index++];
            }
        } else if ( left_index < left_len ) {
            array[i] = left_arr[left_index++];
        } else if ( right_index < right_len ) {
            array[i] = right_arr[right_index++];
        }
    }

    // Frees allocated memory for the left and right subarrays
    free(left_arr);
    free(right_arr);
}