// Exercise 3-2
// Write a function escape(s, t) that converts characters like newline and tab
// into visible escape sequences like \n and \t as it copies the string t to s.
// Use a switch. Write a function for the other direction as well, converting
// escape sequences to real characters.

#include <stdio.h>

#define MAX_LENGTH 1000

int  get_line(char[], int);
void escape(char[], char[]);

int
main(int argc, char** argv) {
    char s[MAX_LENGTH];
    char t[MAX_LENGTH];

    get_line(t, MAX_LENGTH);
    escape(s, t);

    printf("original:\n%s(end)\n", t);
    printf("new:\n%s(end)\n", s);

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
escape(char s[], char t[]) {
    int i = 0;
    int j = 0;

    while ( t[i] != '\0' ) {
        switch ( t[i] ) {
        case '\n':
        case '\t': {
            s[j]     = '\\';
            s[j + 1] = (t[i] == '\n') ? ('n') : ('t');
            j++;
        } break;

        default: {
            s[j] = t[i];
        } break;
        }

        j++;
        i++;
    }

    s[j] = '\0';
}
