// Exercise 2-9
// In a two's complement number system, x &= (x - 1) deletes the rightmost 1-bit
// in x. Use this observation to write a faster version of bitcount.

#include <stdio.h>

int orig_bitcount(unsigned int);
int bitcount(unsigned int);

int
main(int argc, char** argv) {
    int x = -1;

    while ( x++ < 1000 ) {
        printf("%d - %d = %d\n", bitcount(x), orig_bitcount(x),
               bitcount(x) - orig_bitcount(x));
    }

    return 0;
}

int
orig_bitcount(unsigned int x) {
    int b;

    for ( b = 0; x != 0; x >>= 1 ) {
        if ( x & 01 ) {
            b++;
        }
    }

    return b;
}

int
bitcount(unsigned int x) {
    int b = 0;

    while ( x &= (x - 1) ) {
        b++;
    }

    return (b + 1);
}
