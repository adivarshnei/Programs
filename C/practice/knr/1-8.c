// Exercise 1-8
// Write a program to count blanks, tabs and newlines

#include <stdio.h>

int
main(int argc, char** argv) {
    int c;
    int blanks   = 0;
    int tabs     = 0;
    int newlines = 0;

    while ( (c = getchar()) != EOF ) {
        if ( c == ' ' ) {
            blanks++;
        }

        else if ( c == '\t' ) {
            tabs++;
        }

        else if ( c == '\n' ) {
            newlines++;
        }
    }

    printf("Blanks:   %d\n", blanks);
    printf("Tabs:     %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}
