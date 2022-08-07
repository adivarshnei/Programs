// Exercise 2-2
// Write a loop equivalent to the for loop below without using && or ||

// for ( i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i ) {
//    s[i] = c;
// }

#include <stdio.h>

#define MAX_LENGTH 1000

int get_line(char[], int);

int
main(int argc, char** argv) {
    int  len;
    char line[MAX_LENGTH];

    while ( (len = get_line(line, MAX_LENGTH)) > 0 ) {
        printf("%d: %s", len, line);
    }

    return 0;
}

int
get_line(char s[], int lim) {
    int c;
    int i;

    i = 0;

    while ( (c = getchar()) ) {
        if ( (c != EOF) ? ((i < lim - 1) ? ((c != '\n') ? (1) : (0)) : (0))
                        : (0) ) {
            s[i++] = c;
        } else {
            break;
        }
    }

    if ( c == '\n' ) {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}