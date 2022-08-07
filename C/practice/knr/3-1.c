// Exercise 3-1
// Our binary search makes two tests inside the loop, when one would suffice (at
// the price of more tests outside). Write a version with only one test inside
// the loop and measure the difference in run-time

#include <stdio.h>
#include <time.h>
#include <limits.h>

#define MAX_LENGTH           USHRT_MAX
#define MAX_ITERATIONS       (USHRT_MAX * 1000)
#define NOT_FOUND            -1
#define ELEMENT_NOT_IN_ARRAY -1

int  binsearch_original(int, int[], unsigned);
int  binsearch_new(int, int[], unsigned);
void time_test(int[], int (*)(int, int[], unsigned));

int
main(int argc, char** argv) {
    int numbers[MAX_LENGTH];
    int i;

    for ( i = 0; i < MAX_LENGTH; i++ ) {
        numbers[i] = i;
    }

    printf("binsearch_original(): \n");
    time_test(numbers, binsearch_original);

    printf("binsearch_new(): \n");
    time_test(numbers, binsearch_new);

    return 0;
}

int
binsearch_original(int x, int v[], unsigned n) {
    long low, high, mid;

    low  = 0;
    high = n - 1;

    while ( low <= high ) {
        mid = (low + high) / 2;

        if ( x < v[mid] ) {
            high = mid - 1;
        } else if ( x > v[mid] ) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int
binsearch_new(int x, int v[], unsigned n) {
    long low  = 0;
    long mid  = 0;
    long high = n - 1;

    while ( low <= high && v[mid] != x ) {
        mid = (low + high) / 2;

        if ( x < v[mid] ) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ((v[mid] == x) ? (mid) : (NOT_FOUND));
}

void
time_test(int numbers[], int (*function)(int x, int v[], unsigned n)) {
    clock_t time_taken;
    int     index;
    int     i;

    i          = 0;
    time_taken = clock();

    while ( i++ < MAX_ITERATIONS ) {
        index = function(ELEMENT_NOT_IN_ARRAY, numbers, MAX_LENGTH);
    }

    time_taken = clock() - time_taken;

    if ( index == NOT_FOUND ) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", index);
    }

    printf("Function took %lu seconds\n",
           ( unsigned long ) time_taken / CLOCKS_PER_SEC);
}
