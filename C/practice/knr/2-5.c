// Exercise 2-5
// Write the function any(s1, s2) which returns the first location in the string
// s1 where any character from the string s2 occurs, or -1 if s1 contains no
// characters from s2

#include <stdio.h>

#define MAX_LENGTH 1000
#define FAIL       -1

int get_line(char[], int);
int any(char[], char[]);

int
main(int argc, char** argv) {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    get_line(s1, MAX_LENGTH);
    get_line(s2, MAX_LENGTH);

    printf("%d\n", any(s1, s2));
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

int
any(char s1[], char s2[]) {
    int  i       = 0;
    int  min_loc = MAX_LENGTH;
    char c1, c2;

    while ( (c1 = s2[i++]) != '\0' ) {
        int j = 0;

        while ( s1[j] != '\0' ) {
            if ( s1[j] == c1 && j < min_loc ) {
                min_loc = j;
                break;
            }

            j++;
        }
    }

    if ( min_loc == MAX_LENGTH ) {
        return FAIL;
    }

    return min_loc;
}
