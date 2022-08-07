/* Write a C program to find all prime numbers between given interval using function */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************

enum boolFlag {
	FALSE = 1,
	TRUE
}; //enum boolFlag

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************

void printPrimes(int, int);

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int upLim, lowLim;
		int tempNum;

		printf("Enter the range of the numbers (Limits will be switched if entered in wrong order and converted to positive if negative): \n");

		printf("Enter the lower limit: ");
		scanf("%d", & lowLim);

		printf("Enter the upper limit: ");
		scanf("%d", & upLim);

		lowLim = abs(lowLim);
		upLim = abs(upLim);

		if (upLim < lowLim) {
			tempNum = upLim;
			upLim = lowLim;
			lowLim = tempNum;
		} //if (upLim < lowLim)

		printPrimes(lowLim, upLim);

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

void printPrimes(int lowLim, int upLim) {
	loopVar i, j;
	enum boolFlag divisFlag;

	printf("Primes between %d and %d are: \n", lowLim, upLim);

	for (i = lowLim; i <= upLim; i++) {
		divisFlag = FALSE;

		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				divisFlag = TRUE;
				break;
			} //if (i % j == 0)
		} //for (j = 2; j < i; j++)

		if (divisFlag == FALSE && i > 1) {
			printf("%d\t", i);
		} //if (divisFlag == FALSE && i > 1)
	} //for (i = lowLim; i <= upLim; i++)
} //void printPrimes(int lowLim, int upLim)