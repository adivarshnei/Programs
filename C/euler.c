#include <math.h>
#include <stdio.h>

int
main(void) {
    // Enter number of iterations here
    long long iterations = 5;

    float y = 1;
    float x = y * y;

    float interval = 1.0 / iterations;

    printf("%.6f, %.6f\n", x, y);

    for ( long i = 0; i < iterations; i++ ) {
        y = y + interval * (x * x);
        printf("%.6f, %.6f\n", x, y);
        x = x + interval;
    }

    iterations++;
    return 0;
}
