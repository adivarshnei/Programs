// Exercise 3-3
// Write a function expand(s1, s2) that expands shorthand notations like a-z in
// the string s1 into the equivalent commplete list abc...xyz in s2. Allow for
// letters of either case and digits, and be prepared to handle cases like a-b-c
// and a-z0-9 and -a-z. Arrand that a leading or trailing - is taken literally

#include <stdio.h>

#define MAX_LENGTH 1000

int  get_line(char[], int);
void expand(char[], char[]);

int
main(int argc, char** argv) {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    get_line(s1, MAX_LENGTH);
    expand(s1, s2);

    printf("%s\n%s", s1, s2);

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
expand(char s1[], char s2[]) {
    char c;
    int  i = 0;
    int  j = 0;

    while ( (c = s1[i++]) != '\0' ) {
        if ( s1[i] == '-' && s1[i + 1] >= c ) {
            i++;

            while ( c < s1[i] ) {
                s2[j++] = c++;
            }
        } else {
            s2[j++] = c;
        }
    }

    s2[j] = '\0';
}