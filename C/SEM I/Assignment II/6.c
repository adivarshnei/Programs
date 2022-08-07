/* 

Assignemnt II
Name: Adersh Varshnei
6. Write a C Program to find first and last digit of a number

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

int firstDig(long int);
int lastDig(long int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		long int inputNum;

		printf("Enter the number: ");
		scanf("%ld", & inputNum);

		printf("The first digit is %d and last digit is %d", firstDig(abs(inputNum)), lastDig(abs(inputNum)));

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

int firstDig(long int num) {
	for (; num >= 10; num /= 10);

	return num;
} //int firstDig(long int num)

//************************************************************************************************

int lastDig(long int num) {
	return num % 10;
} //int lastDig(long int num) 