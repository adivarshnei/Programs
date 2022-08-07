// 1. Implement recursive linear and binary search and determine the time taken
// to search an element. Repeat the experiment for different values of n, the
// number of elements in the list to be searched and plot a graph of the time
// taken versus n

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX_LENGTH           USHRT_MAX
#define MAX_NUM              100
#define NOT_FOUND            -1
#define ELEMENT_NOT_IN_ARRAY -1
#define ITERATIONS           USHRT_MAX * 100

void gen_rand_arr(int*, long);
void print_arr(int*, int);
void sort_array(int*, int);
int  linear_search(int*, int, int, int);
int  binary_search(int*, int, int, int, int);
void time_taken_linear(int*, int);
void time_taken_binary();

int
main(int argc, char** argv) {
    int array[MAX_LENGTH];
    int len;
    int query;
    int index_found_at;
    int choice;

    srand(time(NULL));

    do {
        printf("Enter array length: ");
        scanf("%d", &len);
    } while ( len > MAX_LENGTH || len < 0 );

    gen_rand_arr(array, len);
    print_arr(array, len);

    do {
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Reset Array\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch ( choice ) {
        case 1: {
            printf("Enter element to search for: ");
            scanf("%d", &query);

            index_found_at = linear_search(array, len, query, len - 1);

            if ( index_found_at == -1 ) {
                printf("Element not found\n");
            } else {
                printf("Element found at index %d\n", index_found_at);
            }

            break;
        }

        case 2: {
            sort_array(array, len);
            printf("Sorted Array: \n");
            print_arr(array, len);

            printf("Enter element to search for: ");
            scanf("%d", &query);

            index_found_at = binary_search(array, len, query, 0, len - 1);

            if ( index_found_at == -1 ) {
                printf("Element not found\n");
            } else {
                printf("Element found at index %d\n", index_found_at);
            }

            break;
        }

        case 3: {
            do {
                printf("Enter array length: ");
                scanf("%d", &len);
            } while ( len > MAX_LENGTH || len < 0 );

            gen_rand_arr(array, len);
            print_arr(array, len);
        }

        case 4: {
            break;
        }

        default: {
            printf("Wrong Choice, Enter Again.");
        }
        }
    } while ( choice != 4 );

    return 0;
}

void
gen_rand_arr(int* array, long len) {
    for ( long i = 0; i < len; i++ ) {
        array[i] = rand() % MAX_NUM;
    }
}

void
print_arr(int array[], int len) {
    for ( int i = 0; i < len; i++ ) {
        printf("%d\t", array[i]);
    }

    printf("\n");
}

void
sort_array(int array[], int len) {
    int temp;

    for ( int i = 0; i < len - 1; i++ ) {
        for ( int j = 0; j < len - 1; j++ ) {
            if ( array[j] > array[j + 1] ) {
                temp         = array[j];
                array[j]     = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int
linear_search(int* array, int len, int query, int loc) {
    if ( loc < 0 ) {
        return NOT_FOUND;
    } else if ( array[loc] == query ) {
        return loc;
    }

    return linear_search(array, len, query, loc - 1);
}

int
binary_search(int* array, int len, int query, int low, int high) {
    if ( low > high ) {
        return NOT_FOUND;
    }

    int mid = (low + high) / 2;

    if ( array[mid] == query ) {
        return mid;
    } else if ( array[mid] < query ) {
        return binary_search(array, len, query, mid + 1, high);
    } else {
        return binary_search(array, len, query, low, mid - 1);
    }
}
