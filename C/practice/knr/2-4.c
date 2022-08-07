// Exercise 2-4
// Write an alternate version of squeeze(s1, s2) that deletes each character in
// s1 that matches any character in the string s2

#include <stdio.h>

#define MAX_LENGTH 1000

int  get_line(char[], int);
void squeeze(char[], char[]);

int
main(int argc, char** argv) {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    get_line(s1, MAX_LENGTH);
    get_line(s2, MAX_LENGTH);

    squeeze(s1, s2);

    printf("%s", s1);

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
squeeze(char s1[], char s2[]) {
    int  i = 0;
    char c1, c2;

    while ( (c1 = s2[i++]) != '\0' ) {
        int j = 0;
        int k = 0;

        while ( s1[j] != '\0' ) {
            if ( s1[j] != c1 ) {
                s1[k++] = s1[j];
            }

            j++;
        }

        s1[k] = '\0';
    }
}
