/* 

Assignemnt III
Name: Adersh Varshnei
6. Write a C Program to check whether a number is Strong number of not

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef unsigned long int longLoopVar;
typedef unsigned long int intArr;

//************************************************************************************************

long int factorial(int);
int strongChk(long int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		loopVar i;
		long int inputNum;
		intArr * strongList;

		printf("Enter the number to be checked: ");
		scanf("%ld", & inputNum);

		if (strongChk(inputNum) == 1) {
			printf("%ld is a Strong Number\n", inputNum);
		} else {
			printf("%ld is not a Strong Number\n", inputNum);
		} //End of extended if clause

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);

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

long int factorial(int num) {
	if (num >= 1) {
		return num * factorial(num - 1);
	} else {
		return 1;
	} //End of extended if clause
} //long int factorial(int num)

//************************************************************************************************

int strongChk(long int num) {
	long int factSum = 0, temp = num;

	for (; temp > 0; temp /= 10) {
		factSum += factorial(temp % 10);
	} //for (; temp > 0; temp /= 10)

	if (factSum == num) {
		return 1;
	} else {
		return 0;
	} //End of extended if clause
} //int strongChk(long int num)