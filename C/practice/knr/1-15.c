// Exercise 1-15
// Rewrite the temperature conversion program to use a function for conversion

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float cel_to_fahr(float);

int
main(int argc, char** argv) {
    float celsius = LOWER;
    float fahr;

    printf("Celsius\tFahrenheit\n");

    while ( celsius <= UPPER ) {
        fahr = cel_to_fahr(celsius);
        printf("%7.0f\t%10.1f\n", celsius, fahr);
        celsius += STEP;
    }

    return 0;
}

float
cel_to_fahr(float celsius) {
    return celsius * (9.0 / 5.0) + 32.0;
}
