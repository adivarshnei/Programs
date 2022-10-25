#include <stdio.h>
#include <stdlib.h>

int
main(void) {
    int* memtestptr = ( int* ) malloc(500 * sizeof(int));
    int  memtestarr[500];

    fprintf(stdout, "%d\n", sizeof(memtestptr) / sizeof(memtestptr[0]));
    fprintf(stdout, "%d\n", sizeof(memtestarr) / sizeof(memtestarr[0]));

    return 0;
}
