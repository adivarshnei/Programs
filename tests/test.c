#include <stdio.h>

void
foo() {
    int a;
    int b = 5;

    while ( b-- )
        ;
}

void
bar() {
    int x;
    int y = 10;

    for ( x = 0; x < y; x++ )
        ;
}

int
main(void) {
    printf("test");

    foo();
    bar();

    return 0;
}
