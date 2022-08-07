// Exercise 1-19
// Write a function reverse(s) that reverses the character string s. Use it to
// write a program that reverses its input a line at a time

#include <stdio.h>

#define MAXLINE 1000
#define SWAP(A, B)      \
    typeof(B) temp = B; \
    B              = A; \
    A              = temp;

int  get_line(char[], int);
void reverse(char line[]);

int
main(int argc, char** argv) {
    int  len;
    char line[MAXLINE];

    while ( (len = get_line(line, MAXLINE)) > 0 ) {
        printf("Original: %s\n", line);

        reverse(line);

        printf("Reversed: %s\n", line);
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
reverse(char line[]) {
    int i = 0;
    int j = 0;

    while ( line[j] != '\0' ) {
        j++;
    }

    j--;

    while ( j > i ) {
        SWAP(line[i], line[j]);
        i++;
        j--;
    }
}
