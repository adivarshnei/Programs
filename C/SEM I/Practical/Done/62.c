/* Write a C program to print all strong numbers between given interval using functions */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************

enum boolFlag {
	FALSE = 1,
	TRUE
};//enum boolFlag

//************************************************************************

typedef unsigned int loopVar;
typedef unsigned long int longLoopVar;
typedef char bufferClear;
typedef unsigned long int intArr;

//************************************************************************

long int factorial(int);
enum boolFlag strongChk(long int);
intArr * retrnStrongNumList(long int, long int, int * );

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		loopVar i;
		long int upLim, lowLim;
		int tempNum;
		intArr * strongList;
		int cardinality = 0;

		printf("Enter the range of the numbers (Limits will be switched if entered in wrong order and converted to positive if negative): \n");

		printf("Enter the lower limit: ");
		scanf("%ld", & lowLim);

		printf("Enter the upper limit: ");
		scanf("%ld", & upLim);

		lowLim = abs(lowLim);
		upLim = abs(upLim);

		if (upLim < lowLim) {
			tempNum = upLim;
			upLim = lowLim;
			lowLim = tempNum;
		}//if (upLim < lowLim)

		strongList = retrnStrongNumList(lowLim, upLim, & cardinality);

		if (cardinality == 0) {
			printf("There are no Strong numbers between %ld and %ld.\n", lowLim, upLim);
		} else {
			printf("The Strong numbers between %ld and %ld are: \n", lowLim, upLim);

			for (i = 0; i < cardinality; i++) {
				printf("%ld \t", strongList[i]);
			}//for (i = 0; i < cardinality; i++)
		}//End of extended if clause

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

long int factorial(int num) {
	if (num >= 1) {
		return num * factorial(num - 1);
	} else {
		return 1;
	}//End of extended if clause
}//long int factorial(int num)

//************************************************************************

enum boolFlag strongChk(long int num) {
	long int factSum = 0, tempNum = num;

	for (; tempNum > 0; tempNum /= 10) {
		factSum += factorial(tempNum % 10);
	}//for (; tempNum > 0; tempNum /= 10)

	if (factSum == num) {
		return TRUE;
	} else {
		return FALSE;
	}//End of extended if clause
}//enum boolFlag strongChk(long int num)

//************************************************************************

intArr * retrnStrongNumList(long int lowLim, long int upLim, int * cardinality) {
	static intArr strongList[10];
	static int repChk;
	longLoopVar i;
	int indexVar = 0;

	if (count > repChk) {
		for (i = 0; i < 10; i++) {
			strongList[i] = 0;
		}//for (i = 0; i < 10; i++)

		repChk = count;
	}//if (count > repChk) 

	for (i = lowLim; i <= upLim; i++) {
		if (strongChk(i) == TRUE) {
			strongList[indexVar] = i;

			indexVar++;
			++( * cardinality);
		}//if (strongChk(i) == TRUE)
	}//for (i = lowLim; i <= upLim; i++) 

	return strongList;
}//intArr * retrnStrongNumList(long int lowLim, long int upLim, int * cardinality)