/* 

Assignemnt II
Name: Adersh Varshnei
7. Write a C Program to swap first and last digits of a number

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

long int firstLastDigSwap(long int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		long int inputNum;

		printf("Enter the number: ");
		scanf("%ld", & inputNum);

		printf("The number with its first and last digits swapped is: %ld", firstLastDigSwap(inputNum));

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

long int firstLastDigSwap(long int num) {
	int firstDig, lastDig;
	long int swapNum = num;
	int digCount = 0;

	for (firstDig = num, lastDig = num % 10; firstDig >= 10; firstDig /= 10, digCount++);

	swapNum -= (lastDig + firstDig * (int) round(pow(10, digCount)));
	swapNum += (firstDig + lastDig * (int) round(pow(10, digCount)));

	return swapNum;
} //long int firstLastDigSwap(long int num)