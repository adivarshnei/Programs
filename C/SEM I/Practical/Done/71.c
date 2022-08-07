/* Write macro definition with arguments for calculation of simple interest and amount. 
Store these macro definitions in a file called "Interest.h". Include this file in your 
program and use the macro definiton for calculating simple interest and amount */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include "Interest.h"

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		float inputPrinc, inputRate, inputTime;
		float interest, resAmount;

		printf("Enter the principal amount (Negative numbers will be converted to positive): ");
		scanf("%f", & inputPrinc);

		printf("Enter the rate of interest (Negative numbers will be converted to positive): ");
		scanf("%f", & inputRate);

		printf("Enter the time period (Negative numbers will be converted to positive): ");
		scanf("%f", & inputTime);

		interest = simpleInt(fabs(inputPrinc), fabs(inputRate), fabs(inputTime));
		resAmount = amount(fabs(inputPrinc), fabs(interest));

		printf("Simple Interest: %.2f\n", interest);
		printf("Result Amount: %.2f\n", resAmount);

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