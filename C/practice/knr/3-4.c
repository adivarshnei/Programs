// Exercise 3-4
// In a two's complement number representaion, our version of itoa does not
// handle the largest negative number, that is, the value of n equal to -(2 ^
// (wordsize - 1)). Modify it to print that value correctly, regardless of the
// machine on which it runs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char[]);
void itoa_orig(int, char[]);
void itoa_new(int, char[]);

int
main(int argc, char** argv) {
    char s[1000];

    itoa_orig(-2147483648, s);
    printf("%s\n", s);

    itoa_new(-2147483648, s);
    printf("%s\n", s);

    return 0;
}

void
reverse(char s[]) {
    int c, i, j;

    for ( i = 0, j = strlen(s) - 1; i < j; i++, j-- ) {
        c    = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void
itoa_orig(int n, char s[]) {
    int i, sign;

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
itoa_new(int n, char s[]) {
    int i, sign;

    sign = n;

    i = 0;

    do {
        s[i++] = abs(n % 10) + '0';
    } while ( (n /= 10) != 0 );

    if ( sign < 0 ) {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}