// Exercise 1-2
// Experiment to find out what happens when printf's argument string contains
// \c, where c is come character not listed above.

#include <stdio.h>

int
main(int argc, char** argv) {
    printf("hello, \nworld\n");
    printf("hello, \tworld\n");
    printf("hello, \bworld\n");
    printf("hello, \"world\n");
    printf("hello, \\world\n");

    return 0;
}