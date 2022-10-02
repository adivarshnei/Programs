#include <stdio.h>
#include <stdlib.h>

int
main(void) {
    int i = 0;

    void* test = ( void* ) malloc(50);

    free(test);

    return 0;
}
