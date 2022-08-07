// Exercise 1-21
// Write a program entab that replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing.

#include <stdio.h>

#define TAB_LENGTH 8
#define MAX_LENGTH 1000

int  get_line(char[], int);
void copy(char[], char[]);
void entab(char[]);

int
main(int argc, char** argv) {
    char line[MAX_LENGTH];

    while ( get_line(line, MAX_LENGTH) > 0 ) {
        printf("%s\n", line);
        entab(line);
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
entab(char line[]) {
    int i           = 0;
    int j           = 0;
    int space_count = 0;
    int tab_count   = 0;

    char new[MAX_LENGTH];

    while ( line[i] != '\0' ) {
        space_count = 0;
        tab_count   = 0;

        while ( line[i] == ' ' ) {
            space_count++;

            if ( (i + 1) % TAB_LENGTH == 0 ) {
                tab_count++;
                space_count = 0;
            }

            i++;
        }

        while ( tab_count-- ) {
            new[j] = '\t';
            j++;
        }

        while ( space_count-- ) {
            new[j] = ' ';
            j++;
        }

        if ( line[i] != ' ' ) {
            new[j++] = line[i++];
        }
    }

    new[j] = '\0';

    copy(line, new);
}
