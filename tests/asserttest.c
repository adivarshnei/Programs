#include <assert.h>

int
main(void) {
    int i = 0;

    while ( 1 ) {
        assert(i++ < 7);
        assert(i * 2 < 10);
    }

    return 0;
}
