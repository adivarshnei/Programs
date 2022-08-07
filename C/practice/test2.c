#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char** argv) {
    int i = 1;
    int s = 1;

    fprintf(stdout, "i: %d, s: %d, n: %d\n", i, s, atoi(argv[1]));

    while ( s <= atoi(argv[1]) ) {
        i++;
        s = s + i;

        fprintf(stdout, "i: %d, s: %d, n: %d\n", i, s, atoi(argv[1]));
    }

    return 0;
}
