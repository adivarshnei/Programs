// Exercise 3-5
// Write the function itob(n, s, b) that converts the integer n into a base b
// character representation in the string s

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH       10000
#define MAX_BASE         62
#define DIGIT_TO_CHAR(X) X + '0'
#define PRINT_BASE(num, num_str, base) \
    itob(num, num_str, base);          \
    printf("%d (base 10) = %10s (base %2d)\n", num, num_str, base);

void reverse(char[]);
void itob(int, char[], int);

int
main(int argc, char** argv) {
    char num_str[MAX_LENGTH];
    int  num  = atoi(argv[1]);
    int  base = 1;

    while ( ++base < MAX_BASE ) {
        PRINT_BASE(num, num_str, base);
    }

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
itob(int n, char s[], int b) {
    int i = 0;

    while ( n > 0 ) {
        if ( n % b < 10 ) {
            s[i++] = DIGIT_TO_CHAR(n % b);
        } else if ( n % b < 36 ) {
            s[i++] = (n % b) - 10 + 'A';
        } else {
            s[i++] = (n % b) - 36 + 'a';
        }

        n /= b;
    }

    s[i] = '\0';
    reverse(s);
}
