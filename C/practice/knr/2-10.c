// Exercise 2-10
// Rewrite the function lower, which converts upper case letters to lower case,
// with a conditional expression instead of if-else

#include <stdio.h>

#define MAX_LENGTH 1000

int  get_line(char[], int);
void lower(char[]);

int
main(int argc, char** argv) {
    char line[MAX_LENGTH];

    get_line(line, MAX_LENGTH);
    printf("Original: %s\n", line);

    lower(line);

    printf("Lowered:  %s\n", line);
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
lower(char line[]) {
    int i = -1;

    while ( line[++i] != '\0' ) {
        line[i] = (line[i] >= 'A' && line[i] <= 'Z') ? ('a' - 'A' + line[i])
                                                     : (line[i]);
    }
}
