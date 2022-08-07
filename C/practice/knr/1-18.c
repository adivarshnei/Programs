// Exercise 1-18
// Write a program to remove trailing blanks and tabs from each line of input,
// and to delete entirely blank lines

#include <stdio.h>

#define TRUE       1
#define EMPTY_LINE -1
#define MAXLINE    1000

int get_line(char[], int);
int remove_trailing(char[]);

int
main(int argc, char** argv) {
    int  len;
    int  new_len;
    char line[MAXLINE];

    while ( TRUE ) {
        len     = get_line(line, MAXLINE);
        new_len = remove_trailing(line);

        if ( new_len != EMPTY_LINE ) {
            printf("%d: %s(end)\n", new_len, line);
        } else {
            continue;
        }
    }

    return 0;
}

int
get_line(char line[], int lim) {
    int c;
    int i = 0;

    while ( (c = getchar()) != '\n' && i < lim - 1 ) {
        if ( c == EOF ) {
            break;
        }

        line[i++] = c;
    }

    line[i] = '\0';

    if ( i == 0 ) {
        return EMPTY_LINE;
    } else {
        return i;
    }
}

int
remove_trailing(char line[]) {
    int i = 0;

    while ( line[i] != '\0' ) {
        i++;
    }

    i--;

    while ( line[i] == ' ' || line[i] == '\t' ) {
        line[i--] = '\0';
    }

    return i;
}
