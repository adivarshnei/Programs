// Exercise 1-20
// Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop.

#include <stdio.h>

#define TAB_LENGTH 8
#define MAX_LENGTH 1000

int  get_line(char[], int);
void copy(char[], char[]);
void detab(char[]);

int
main(int argc, char** argv) {
    char line[MAX_LENGTH];

    while ( get_line(line, MAX_LENGTH) > 0 ) {
        detab(line);
        printf("%s\n", line);
    }

    return 0;
}

int
get_line(char line[], int lim) {
    int c;
    int i = 0;

    while ( (c = getchar()) != EOF ) {
        if ( i >= lim - 1 || c == '\n' ) {
            break;
        }

        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

void
copy(char to[], char from[]) {
    int i = 0;

    while ( (to[i] = from[i]) != '\0' ) {
        i++;
    }
}

void
detab(char line[]) {
    int i = 0;
    int j = 0;
    int k;

    char new[MAX_LENGTH];

    while ( line[i] != '\0' ) {
        if ( line[i] == '\t' ) {
            k = TAB_LENGTH - (j % TAB_LENGTH) + 1;

            while ( --k ) {
                new[j] = ' ';
                j++;
            }

            j--;
        } else {
            new[j] = line[i];
        }

        i++;
        j++;
    }

    new[j] = '\0';

    copy(line, new);
}
