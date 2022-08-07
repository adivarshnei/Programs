// Exercise 1-23
// Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments do not
// nest

#include <stdio.h>

#define MAX_LENGTH     3000
#define IN_COMMENT     -1
#define NOT_IN_COMMENT 0

int  get_line(char[], int);
void print_without_comments(char[]);

int
main(int argc, char** argv) {
    char line[MAX_LENGTH];

    get_line(line, MAX_LENGTH);
    print_without_comments(line);

    return 0;
}

int
get_line(char line[], int lim) {
    int c;
    int i = 0;

    while ( (c = getchar()) != EOF ) {
        if ( i >= lim - 1 ) {
            break;
        }

        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

void
print_without_comments(char line[]) {
    int i     = 0;
    int state = NOT_IN_COMMENT;

    while ( line[i] != '\0' ) {
        if ( line[i] == '/' && line[i + 1] == '/' ) {
            i += 2;

            while ( line[i] != '\n' ) {
                i++;
            }
        }

        if ( line[i] == '/' && line[i + 1] == '*' ) {
            state = IN_COMMENT;
            i += 2;
        }

        if ( line[i] == '*' && line[i + 1] == '/' ) {
            state = NOT_IN_COMMENT;
            i += 2;
        }

        if ( state == NOT_IN_COMMENT ) {
            printf("%c", line[i]);
        }

        i++;
    }
}
