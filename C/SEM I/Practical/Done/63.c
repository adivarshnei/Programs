/* Write a C program to find power of any number using recursion */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************

long int powFunc(int, int);

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputBase, inputPower;
		long unsigned int result;

		printf("Enter the required values: \n");

		printf("Enter the base: ");
		scanf("%u", & inputBase);

		printf("Enter the power (Negative values will be considered to be positive): ");
		scanf("%u", & inputPower);

		result = powFunc(inputBase, abs(inputPower));

		printf("%d ^ %d = %ld", inputBase, abs(inputPower), result);

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);
		scanf("%c", & temp);

		count++;

		if (count >= 15) {
			printf("Abnormal END\n");

			getch();
			exit(0);
		} //if (count >= 15) 
	} //while (rep == 1) 

	printf("Normal END\n");

	getch();
	return 0;
} //int main(void)

//************************************************************************

long int powFunc(int base, int power) {
	if (power > 0) {
		return base * powFunc(base, power - 1);
	} else {
		return 1;
	}//End of extended if clause
}//long int powFunc(int base, int power)