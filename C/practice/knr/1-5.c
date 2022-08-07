// Exercise 1-5
// Modify the temperature conversion program to print the table in reverse
// order, that is from 300 degrees to 0

#include <stdio.h>

int
main(int argc, char** argv) {
    float fahr, celsius;
    int   lower, upper, step;

    lower = 0;
    upper = 300;
    step  = 20;

    fahr = upper;

    printf("Fahrenheit\tCelsius\n");

    while ( fahr >= lower ) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f\t%7.1f\n", fahr, celsius);
        fahr = fahr - step;
    }

    return 0;
}
