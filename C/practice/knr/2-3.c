// Exercise 2-3
// Write the function htoi(s) which converts a string of hexadecimal digits
// (including an optional 0x and 0X) into its equivalent integer value. The
// allowable digits are 0 through 9, a through f, and A through F

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

enum Bool {
    FALSE = 0,
    TRUE  = 1
};

int       get_hex(char[], int);
void      hex_tolower(char[], int);
void      hex_toupper(char[], int);
enum Bool is_valid(char[], int);
int       remove_prefix(char[], int);
long      htoi(char[], int);

int
main(int argc, char** argv) {
    int  len;
    char hex_str[MAX_LENGTH];

    len = get_hex(hex_str, MAX_LENGTH);

    hex_tolower(hex_str, len);
    len = remove_prefix(hex_str, len);

    if ( is_valid(hex_str, len) ) {
        long hex_val = htoi(hex_str, len);
        hex_toupper(hex_str, len);

        printf("%d = 0x%s", hex_val, hex_str);
    } else {
        hex_toupper(hex_str, len);
        printf("%s is not a valid hexadecimal number.", hex_str);
    }

    return 0;
}

int
get_hex(char hex_str[], int lim) {
    int c;
    int i = 0;

    while ( (c = getchar()) != EOF ) {
        if ( i >= lim - 1 || c == '\n' ) {
            break;
        }

        hex_str[i++] = c;
    }

    hex_str[i] = '\0';

    return i;
}

void
hex_tolower(char hex_str[], int len) {
    int i = 0;

    while ( i < len ) {
        hex_str[i] = tolower(hex_str[i]);
        i++;
    }
}

void
hex_toupper(char hex_str[], int len) {
    int i = 0;

    while ( i < len ) {
        hex_str[i] = toupper(hex_str[i]);
        i++;
    }
}

enum Bool
is_valid(char hex_str[], int len) {
    int i = 0;

    while ( i < len ) {
        if ( ! (isdigit(hex_str[i]) ||
                (hex_str[i] >= 'a' && hex_str[i] <= 'f')) ) {
            return FALSE;
        }

        i++;
    }

    return TRUE;
}

int
remove_prefix(char hex_str[], int len) {
    int i = 0;

    if ( hex_str[0] == '0' && hex_str[1] == 'x' ) {
        while ( i <= len - 2 ) {
            hex_str[i] = hex_str[i + 2];
            i++;
        }

        return (i - 1);
    } else {
        return len;
    }
}

long
htoi(char hex_str[], int len) {
    int  i   = 0;
    long num = 0;

    while ( i < len ) {
        if ( isdigit(hex_str[i]) ) {
            num *= 16;
            num += hex_str[i] - '0';
        } else {
            num *= 16;
            num += hex_str[i] - 'a' + 10;
        }

        i++;
    }

    return num;
}
