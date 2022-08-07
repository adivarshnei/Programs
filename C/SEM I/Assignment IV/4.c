/* 

Assignemnt IV
Name: Adersh Varshnei
4. Write a C Program to find sum of all even or odd numbers in given range using recursion

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

enum boolType {
	ODD = 1,
	EVEN
}; //enum boolType

//************************************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************************************

long int seriesSum(int, int, enum boolType);

//************************************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int lowLim, upLim, tempNum;
		enum boolType seriesType;
		long int sum;

		printf("Enter the range of the numbers (Limits will be switched if entered in wrong order and converted to positive if negative): \n");

		printf("Enter the lower limit: ");
		scanf("%d", & lowLim);

		printf("Enter the upper limit: ");
		scanf("%d", & upLim);

		do {
			printf("Enter the series type (ODD = 1, EVEN = 2): ");
			scanf("%d", & seriesType);

			if (seriesType != ODD && seriesType != EVEN) {
				printf("Invalid Entry\n");
			} //if (seriesType != ODD && seriesType != EVEN)
		} while (seriesType != ODD && seriesType != EVEN);

		lowLim = abs(lowLim);
		upLim = abs(upLim);

		if (upLim < lowLim) {
			tempNum = upLim;
			upLim = lowLim;
			lowLim = tempNum;
		}

		sum = seriesSum(lowLim, upLim, seriesType);

		if (seriesType == ODD) {
			printf("Sum of odd numbers between %d and %d is: %ld\n", lowLim, upLim, sum);
		} else if (seriesType == EVEN) {
			printf("Sum of even numbers between %d and %d is: %ld\n", lowLim, upLim, sum);
		} //End of extended if clause

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

//************************************************************************************************

long int seriesSum(int lowLim, int upLim, enum boolType seriesType) {
	if ((lowLim % 2 == 0 && seriesType == ODD) || (lowLim % 2 == 1 && seriesType == EVEN)) {
		lowLim += 1;
	} //if ((lowLim % 2 == 0 && seriesType == ODD) || (lowLim % 2 == 1 && seriesType == EVEN))

	if (lowLim <= upLim) {
		return lowLim + seriesSum(lowLim + 2, upLim, seriesType);
	} else {
		return 0;
	} //End of extended if clause
} //long int seriesSum(int lowLim, int upLim, enum boolType seriesType)