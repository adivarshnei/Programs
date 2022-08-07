/* 

Assignemnt IV
Name: Adersh Varshnei
7. Write a C Program to find sum of digits of a given number using recursion

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************************************

int digitSum(int);

//************************************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputNum, numDigSum;

		printf("Enter the number (Negative numbers will be considered to be positive): ");
		scanf("%d", & inputNum);

		numDigSum = digitSum(abs(inputNum));

		printf("Sum of the digits of %d is %d", inputNum, numDigSum);

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

int digitSum(int num) {
	if (num != 0) {
		return ((num % 10) + digitSum(num / 10));
	} else {
		return 0;
	} //End of extended if clause
} //int digitSum(int num)