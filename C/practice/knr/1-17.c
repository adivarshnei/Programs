// Exercise 1-17
// Write a program to print all input lines that are longer than 80 characters

#include <stdio.h>

#define MAXLINE 1000

int get_line(char[], int);

int
main(int argc, char** argv) {
    int  len;
    char line[MAXLINE];

    while ( (len = get_line(line, MAXLINE)) > 0 ) {
        if ( len > 80 ) {
            printf("%d: %s\n", len, line);
        } else {
            printf("Line smaller than 80 chars\n");
        }
    }

    return 0;
}

int
get_line(char s[], int lim) {
    int c;
    int i = 0;

    while ( (c = getchar()) != EOF ) {
        if ( i >= lim - 1 || c == '\n' ) {
            break;
        }

        s[i++] = c;
    }

    s[i] = '\0';

    return i;
}
