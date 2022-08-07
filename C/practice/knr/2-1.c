// Exercise 2-1
// Write a program to determine the ranges of char, short, int, and long
// variables, both signed and unsigned, by printing appropriate values from
// standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types.

#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MANTISSA  (1 + (pow(2, -1) * (1 - pow(2, -23))) / (1 - pow(2, -1)))
#define FLOAT_MAX (pow(2, pow(2, 8) - 128) * MANTISSA)

#define BITVAL(TYPE)     (sizeof(TYPE) * 8)
#define MIN_SGND(TYPE)   -( long int ) pow(2, BITVAL(TYPE) - 1)
#define MAX_SGND(TYPE)   ( long int ) pow(2, BITVAL(TYPE) - 1) - 1
#define MAX_UNSGND(TYPE) ( unsigned long int ) pow(2, BITVAL(TYPE)) - 1

int
main(int argc, char** argv) {
    printf("+------------------------------------------------------+\n");
    printf("|                   From <limits.h>                    |\n");
    printf("+--------------------+----------------+----------------+\n");
    printf("|        Type        |  Lower Limit   |  Upper Limit   |\n");
    printf("+--------------------+----------------+----------------+\n");
    printf("| signed char        | %14ld | %14ld |\n", ( long int ) SCHAR_MIN,
           ( long int ) SCHAR_MAX);
    printf("| unsigned char      | %14ld | %14ld |\n", ( long int ) 0,
           ( long int ) UCHAR_MAX);
    printf("| char               | %14ld | %14ld |\n", ( long int ) CHAR_MIN,
           ( long int ) CHAR_MAX);
    printf("| signed short int   | %14ld | %14ld |\n", ( long int ) SHRT_MIN,
           ( long int ) SHRT_MAX);
    printf("| unsigned short int | %14ld | %14ld |\n", ( long int ) 0,
           ( long int ) USHRT_MAX);
    printf("| int                | %14ld | %14ld |\n", ( long int ) INT_MIN,
           ( long int ) INT_MAX);
    printf("| unsigned int       | %14lu | %14lu |\n", ( unsigned long int ) 0,
           ( unsigned long int ) UINT_MAX);
    printf("| long int           | %14ld | %14ld |\n", ( long int ) LONG_MIN,
           ( long int ) LONG_MAX);
    printf("| unsigned long int  | %14lu | %14lu |\n", ( unsigned long int ) 0,
           ( unsigned long int ) ULONG_MAX);
    printf("+--------------------+----------------+----------------+\n\n");

    printf("+------------------------------------------------------+\n");
    printf("|                       Computed                       |\n");
    printf("+--------------------+----------------+----------------+\n");
    printf("|        Type        |  Lower Limit   |  Upper Limit   |\n");
    printf("+--------------------+----------------+----------------+\n");
    printf("| signed char        | %14ld | %14ld |\n", MIN_SGND(signed char),
           MAX_SGND(signed char));
    printf("| unsigned char      | %14ld | %14lu |\n", 0,
           MAX_UNSGND(unsigned char));
    printf("| char               | %14ld | %14ld |\n", MIN_SGND(char),
           MAX_SGND(char));
    printf("| signed short int   | %14ld | %14ld |\n",
           MIN_SGND(signed short int), MAX_SGND(signed short int));
    printf("| unsigned short int | %14ld | %14lu |\n", 0,
           MAX_UNSGND(unsigned short int));
    printf("| int                | %14ld | %14ld |\n", MIN_SGND(int) - 1,
           MAX_SGND(int) + 1);
    printf("| unsigned int       | %14ld | %14lu |\n", 0,
           MAX_UNSGND(unsigned int));
    printf("| long int           | %14ld | %14ld |\n", MIN_SGND(long int) - 1,
           MAX_SGND(long int) + 1);
    printf("| unsigned long int  | %14ld | %14lu |\n", 0,
           MAX_UNSGND(unsigned long int));
    printf("| float              | %14E | %14E |\n", -FLOAT_MAX, FLOAT_MAX);
    printf("+--------------------+----------------+----------------+\n\n");

    return 0;
}