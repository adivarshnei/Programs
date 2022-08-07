/* 

Assignemnt II
Name: Adersh Varshnei
8. Write a C Program to find frequency of each digit in each integer

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

void freqTable(long int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		loopVar i;
		long int inputNum;

		printf("Enter the number: ");
		scanf("%ld", & inputNum);

		freqTable(inputNum);

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

void freqTable(long int num) {
	int freqTable[10][2];
	int digit;
	loopVar i;

	num = abs(num);
	
	printf("\nFrequency Table of %ld:\n", num);

	for (i = 0; i < 10; i++) {
		freqTable[i][0] = i;
		freqTable[i][1] = 0;
	} //for (i = 0; i < 10; i++) 

	for (; num > 0; num /= 10) {
		digit = num % 10;

		freqTable[digit][1]++;
	} //for (; num > 0; num /= 10)

	printf("|---------+-----------|\n");
	printf("|  Digit  | Frequency |\n");
	printf("|---------+-----------|\n");

	for (i = 0; i < 10; i++) {
		printf("|%5d    |%6d     |\n", freqTable[i][0], freqTable[i][1]);
	} //for (i = 0; i < 10; i++)

	printf("|---------+-----------|\n");
} //void freqTable(long int num)