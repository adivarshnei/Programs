#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH          20
#define MAX_ELEM            1000
#define COLOR_BLACK_CODE    "\033[0;30m"
#define COLOR_RED_CODE      "\033[0;31m"
#define COLOR_GREEN_CODE    "\033[0;32m"
#define COLOR_YELLOW_CODE   "\033[0;33m"
#define COLOR_BLUE_CODE     "\033[0;34m"
#define COLOR_PURPLE_CODE   "\033[0;35m"
#define COLOR_CYAN_CODE     "\033[0;36m"
#define COLOR_WHITE_CODE    "\033[0:37m"
#define COLOR_RESET_CODE    "\033[0m"
#define COLORED_TEXT(COLOR) fprintf(stdout, COLOR)
#define COLOR_RESET()       fprintf(stdout, COLOR_RESET_CODE)

#define SWAP(TYPE, A, B) \
    TYPE TEMP = A;       \
    A         = B;       \
    B         = TEMP;

enum Color {
    BLACK  = 0,
    RED    = 1,
    GREEN  = 2,
    YELLOW = 3,
    BLUE   = 4,
    PURPLE = 5,
    CYAN   = 6,
    WHITE  = 7
};

void gen_rand_arr(int*, int);
void print_arr(int*, int);
void print_pivot_arr(int*, int, int, int, int, enum Color);
int  partition(int*, int, int, int);
void quick_sort(int*, int, int, int);

int
main(int argc, char** argv) {
    srand(time(NULL));

    int array[MAX_LENGTH];

    int len = MAX_LENGTH;

    COLORED_TEXT(COLOR_BLUE_CODE);
    fprintf(stdout, "Pivot initial position\n");
    COLORED_TEXT(COLOR_RED_CODE);
    fprintf(stdout, "Pivot final position\n");
    COLORED_TEXT(COLOR_GREEN_CODE);
    fprintf(stdout, "Subarry under consideration\n");
    COLORED_TEXT(COLOR_YELLOW_CODE);
    fprintf(stdout, "Subarray lower than pivot\n");
    COLORED_TEXT(COLOR_PURPLE_CODE);
    fprintf(stdout, "Subarray greater than pivot\n");
    COLOR_RESET();

    gen_rand_arr(array, len);
    print_arr(array, len);

    quick_sort(array, len, 0, len - 1);

    print_arr(array, len);

    return 0;
}

void
gen_rand_arr(int* array, int len) {
    for ( int i = 0; i < len; i++ ) {
        array[i] = rand() % MAX_ELEM;
    }
}

void
print_arr(int* array, int len) {
    for ( int i = 0; i < len; i++ ) {
        fprintf(stdout, "%4d", array[i]);
    }

    fprintf(stdout, "\n");
}

void
print_pivot_arr(int*       array,
                int        len,
                int        pivot_index,
                int        start,
                int        end,
                enum Color color) {
    for ( int i = 0; i < len; i++ ) {
        if ( i != pivot_index ) {
            if ( i >= start && i <= end ) {
                if ( color == RED ) {
                    if ( i >= start && i <= pivot_index ) {
                        COLORED_TEXT(COLOR_YELLOW_CODE);
                        fprintf(stdout, "%4d", array[i]);
                    } else if ( i >= pivot_index && i <= end ) {
                        COLORED_TEXT(COLOR_PURPLE_CODE);
                        fprintf(stdout, "%4d", array[i]);
                    }
                } else {
                    COLORED_TEXT(COLOR_GREEN_CODE);
                    fprintf(stdout, "%4d", array[i]);
                }
            } else {
                COLORED_TEXT(COLOR_BLACK_CODE);
                fprintf(stdout, "%4d", array[i]);
            }
        } else {
            switch ( color ) {
            case BLACK: {
                COLORED_TEXT(COLOR_BLACK_CODE);
                fprintf(stdout, "%4d", array[i]);
            } break;

            case RED: {
                COLORED_TEXT(COLOR_RED_CODE);
                fprintf(stdout, "%4d", array[i]);
            } break;

            case GREEN: {
                COLORED_TEXT(COLOR_GREEN_CODE);
                fprintf(stdout, "%4d", array[i]);
            } break;

            case YELLOW: {
                COLORED_TEXT(COLOR_YELLOW_CODE);
                fprintf(stdout, "%4d", array[i]);
            } break;

            case BLUE: {
                COLORED_TEXT(COLOR_BLUE_CODE);
                fprintf(stdout, "%4d", array[i]);
            } break;

            case PURPLE: {
                COLORED_TEXT(COLOR_PURPLE_CODE);
                fprintf(stdout, "%4d", array[i]);
            } break;

            case CYAN: {
                COLORED_TEXT(COLOR_CYAN_CODE);
                fprintf(stdout, "%4d", array[i]);
            } break;

            case WHITE: {
                COLORED_TEXT(COLOR_WHITE_CODE);
                fprintf(stdout, "%4d", array[i]);
            } break;
            }
        }

        COLOR_RESET();
    }

    fprintf(stdout, "\n");
}

int
partition(int* array, int len, int start, int end) {
    int pivot_index = end;
    int i           = (start - 1);

    print_pivot_arr(array, len, pivot_index, start, end, BLUE);

    for ( int j = start; j < end; j++ ) {
        if ( array[j] < array[pivot_index] ) {
            i++;

            SWAP(int, array[i], array[j]);
        }
    }

    pivot_index = i + 1;
    SWAP(int, array[pivot_index], array[end]);
    print_pivot_arr(array, len, pivot_index, start, end, RED);

    return pivot_index;
}

void
quick_sort(int* array, int len, int start, int end) {
    int index;

    if ( start < end ) {
        index = partition(array, len, start, end);

        quick_sort(array, len, start, index - 1);
        quick_sort(array, len, index + 1, end);
    }
}
