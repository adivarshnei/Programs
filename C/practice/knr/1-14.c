// Exercise 1-14
// Write a program to print a histogram of the frequencies of different
// characters in its input

#include <stdio.h>

#define ASCII_START 32
#define ASCII_END   126
#define LEN         ASCII_END - ASCII_START

int
main(int argc, char** argv) {
    int c;
    int freq[LEN];

    for ( int i = 0; i < LEN; i++ ) {
        freq[i] = 0;
    }

    while ( (c = getchar()) != EOF ) {
        freq[c - ASCII_START]++;
    }

    for ( int i = 0; i < LEN; i++ ) {
        printf("'%c': %d\n", ASCII_START + i, freq[i]);
    }

    return 0;
}