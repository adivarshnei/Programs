// Exercise 3-6
// Write a version of itoa that accepts three arguments instead of two. The
// third argument is the minimum field width, the converted number must be
// padded with blanks on the left if necessary to make it wide enough

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void reverse(char[]);
void itoa_orig(int, char[]);
void itoa_new(int, char[], int);

int
main(int argc, char** argv) {
    char num_str[MAX_LENGTH];

    itoa_orig(-100, num_str);
    printf("%s\n", num_str);

    itoa_new(-100, num_str, 7);
    printf("%s\n", num_str);

    return 0;
}

void
reverse(char s[]) {
    int c;
    int i = 0;
    int j = strlen(s) - 1;

    while ( i < j ) {
        c    = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
    }
}

void
itoa_orig(int n, char s[]) {
    int i;
    int sign;

    if ( (sign = n) < 0 ) {
        n = -n;
    }

    i = 0;

    do {
        s[i++] = n % 10 + '0';
    } while ( (n /= 10) > 0 );

    if ( sign < 0 ) {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}

void
itoa_new(int n, char s[], int width) {
    int i;
    int sign;

    if ( (sign = n) < 0 ) {
        n = -n;
    }

    i = 0;

    do {
        s[i++] = n % 10 + '0';
    } while ( (n /= 10) > 0 );

    if ( sign < 0 ) {
        s[i++] = '-';
    }

    while ( i < width ) {
        s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);
}