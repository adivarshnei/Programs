// 2. Write a program to implement Selection, Bubble and Insertion Sorts

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 20
#define MAX_ELEM   100
#define DELAY_TIME 50
#define SWAP(TYPE, A, B) \
    TYPE temp = A;       \
    A         = B;       \
    B         = temp;

struct Array {
    int array[MAX_LENGTH];
    int len;
};

void delay(int);
void gen_rand_arr(int*, int);
void print_arr(struct Array);
void selection_sort(struct Array);
void bubble_sort(struct Array);
void insertion_sort(struct Array);

int
main(int argc, char** argv) {
    struct Array array;
    int          choice;

    array.len = MAX_LENGTH;

    srand(time(NULL));
    gen_rand_arr(array.array, array.len);

    do {
        fprintf(stdout, "Base Array:\n");
        print_arr(array);
        fprintf(stdout, "\n");

        fprintf(stdout, "1. Bubble Sort\n");
        fprintf(stdout, "2. Selection Sort\n");
        fprintf(stdout, "3. Insertion Sort\n");
        fprintf(stdout, "4. Reseed Array\n");
        fprintf(stdout, "5. Exit\n");
        fprintf(stdout, "Enter Choice: ");
        fscanf(stdin, "%d", &choice);

        switch ( choice ) {
        case 1: {
            bubble_sort(array);
            break;
        }

        case 2: {
            selection_sort(array);
            break;
        }

        case 3: {
            insertion_sort(array);
            break;
        }

        case 4: {
            srand(time(NULL));
            gen_rand_arr(array.array, array.len);
            break;
        }

        case 5: {
            break;
        }

        default: {
            break;
        }
        }
    } while ( choice != 5 );

    return 0;
}

void
delay(int sec) {
    clock_t start = clock();

    while ( clock() < start + sec )
        ;
}

void
gen_rand_arr(int* array, int len) {
    for ( int i = 0; i < len; i++ ) {
        array[i] = rand() % MAX_ELEM;
    }
}

void
print_arr(struct Array array) {
    for ( int i = 0; i < array.len; i++ ) {
        fprintf(stdout, "%3d ", array.array[i]);
    }

    fprintf(stdout, "\n");
}

void
selection_sort(struct Array array) {
    int min;
    int min_index;

    for ( int i = 0; i < array.len - 1; i++ ) {
        min       = array.array[i];
        min_index = i;

        for ( int j = i + 1; j < array.len; j++ ) {
            if ( array.array[j] < min ) {
                min       = array.array[j];
                min_index = j;
            }
        }

        SWAP(int, array.array[min_index], array.array[i]);
        // delay(DELAY_TIME);
        // fprintf(stdout, "\r%3d: ", array[i]);
        print_arr(array);
    }
}

void
bubble_sort(struct Array array) {
    for ( int i = 0; i < array.len; i++ ) {
        for ( int j = 0; j < array.len - i; j++ ) {
            if ( array.array[j] > array.array[j + 1] ) {
                SWAP(int, array.array[j], array.array[j + 1]);
                delay(DELAY_TIME);
                fprintf(stdout, "\r%3d: ", array.array[j + 1]);
                print_arr(array);
            }
        }
    }
}

void
insertion_sort(struct Array array) {
    int element;

    for ( int i = 1; i < array.len; i++ ) {
        element = array.array[i];

        for ( int j = i; j > 0; j-- ) {
            if ( array.array[j - 1] > array.array[j] ) {
                SWAP(int, array.array[j - 1], array.array[j]);
                // delay(DELAY_TIME);
                // fprintf(stdout, "\r%3d: ", array[j - 1]);
                print_arr(array);
            }
        }
    }
}