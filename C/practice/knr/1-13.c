// Exercise 1-13
// Write a program to print a histogram of the lengths of the words in its
// input.

#include <stdio.h>

#define ARRAY_LEN 20

int
main(int argc, char** argv) {
    int c;
    int len;
    int lengths[ARRAY_LEN + 1];

    for ( int i = 0; i < ARRAY_LEN + 1; i++ ) {
        lengths[i] = 0;
    }

    while ( (c = getchar()) != EOF ) {
        if ( c == ' ' || c == '\t' || c == '\n' ) {
            if ( len >= ARRAY_LEN ) {
                lengths[ARRAY_LEN]++;
            } else {
                lengths[len - 1]++;
            }

            len = 0;
        }

        len++;
    }

    printf("Histogram:\n");

    for ( int i = 0; i < ARRAY_LEN + 1; i++ ) {
        if ( i == ARRAY_LEN ) {
            printf(">%d: ", ARRAY_LEN);
        } else {
            printf("%3d: ", i);
        }

        for ( int j = 0; j < lengths[i]; j++ ) {
            printf("#");
        }

        printf("\n");
    }

    printf("\n\n");

    int max = lengths[0];

    for ( int i = 1; i < ARRAY_LEN + 1; i++ ) {
        if ( lengths[i] > max ) {
            max = lengths[i];
        }
    }

    for ( int i = 0; i < max; i++ ) {
        for ( int j = 0; j < ARRAY_LEN + 1; j++ ) {
            if ( lengths[j] >= max - i ) {
                printf("###");
            } else {
                printf("   ");
            }

            printf(" ");
        }

        printf("\n");
    }

    for ( int i = 0; i < ARRAY_LEN; i++ ) {
        printf("%3d ", i);
    }

    printf(">%d", ARRAY_LEN);

    return 0;
}
