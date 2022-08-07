// Exercise 1-4
// Write a program to print the corresponding Celsius to Fahrenheit table

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int
main(int argc, char** argv) {
    float celsius = LOWER;
    float fahr;

    printf("Celsius\tFahrenheit\n");

    while ( celsius <= UPPER ) {
        fahr = celsius * (9.0 / 5.0) + 32.0;
        printf("%7.0f\t%10.1f\n", celsius, fahr);
        celsius += STEP;
    }

    return 0;
}