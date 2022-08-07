// Exercise 1-9
// Write a program to copy its input to its output, replacing each string of one
// or more blanks by a single blank

#include <stdio.h>

int
main(int argc, char** argv) {
    int c = getchar();

    while ( c != EOF ) {
        if ( c != ' ' ) {
            putchar(c);
        } else {
            c = getchar();

            if ( c != ' ' ) {
                putchar(' ');
            }

            continue;
        }

        c = getchar();
    }

    return 0;
}