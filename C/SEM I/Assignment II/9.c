/* 

Assignemnt II
Name: Adersh Varshnei
9. Write a C Program to enter a number and print it in words

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

int * numToArr(int);
void printDigitWord(int);
void numToWord(int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputNum;

		do {
			printf("Enter the number(Between -9999 and 9999): ");
			scanf("%d", & inputNum);

			if (abs(inputNum) > 10000) {
				printf("Invalid entry. Please enter number again.\n");
			} //if (abs(inputNum) > 10000)
		} while (abs(inputNum) > 10000);

		printf("The number in words is: ");
		numToWord(inputNum);

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

int * numToArr(int num) {
	static int numArr[5];
	loopVar i;
	static int repChk;

	if (count > repChk) {
		for (i = 0; i < 5; i++) {
			numArr[i] = 0;
		} //for (i = 0; i < 5; i++)

		repChk = count;
	} //if (count > repChk)

	if (num < 0) {
		numArr[0] = 1;
	} else {
		numArr[0] = 0;
	} //End of extended if clause

	num = abs(num);

	for (i = 4; num > 0; num /= 10, i--) {
		numArr[i] = num % 10;
	} //for (i = 4; num > 0; num /= 10, i--)

	return numArr;
} //int * numToArr(int num)

//************************************************************************************************

void printDigitWord(int num) {
	switch (num) {
		case 0:
			break;

		case 1:
			printf("One");
			break;

		case 2:
			printf("Two");
			break;

		case 3:
			printf("Three");
			break;

		case 4:
			printf("Four");
			break;

		case 5:
			printf("Five");
			break;

		case 6:
			printf("Six");
			break;

		case 7:
			printf("Seven");
			break;

		case 8:
			printf("Eight");
			break;

		case 9:
			printf("Nine");
			break;
	} //switch (num)
} //void printDigitWord(int num)

//************************************************************************************************

void numToWord(int num) {
	int * numArr;
	loopVar i;

	if (num == 0) {
		printf("Zero");
	} else {
		numArr = numToArr(num);

		if (numArr[0] == 1) {
			printf("Negative ");
		} //if (numArr[0] == 1)

		printDigitWord(numArr[1]);

		if (numArr[1] != 0) {
			printf(" Thousand ");
		} //if (numArr[1] != 0)

		printDigitWord(numArr[2]);

		if (numArr[2] != 0) {
			printf(" Hundred ");
		} //if (numArr[2] != 0)

		if (numArr[3] * 10 + numArr[4] < 20) {
			switch (numArr[3] * 10 + numArr[4]) {
				case 0:
					printf("");
					break;

				case 1:
					printf("One");
					break;

				case 2:
					printf("Two");
					break;

				case 3:
					printf("Three");
					break;

				case 4:
					printf("Four");
					break;

				case 5:
					printf("Five");
					break;

				case 6:
					printf("Six");
					break;

				case 7:
					printf("Seven");
					break;

				case 8:
					printf("Eight");
					break;

				case 9:
					printf("Nine");
					break;

				case 10:
					printf("Ten");
					break;

				case 11:
					printf("Eleven");
					break;

				case 12:
					printf("Twelve");
					break;

				case 13:
					printf("Thirteen");
					break;

				case 14:
					printf("Fourteen");
					break;

				case 15:
					printf("Fifteen");
					break;

				case 16:
					printf("Sixteen");
					break;

				case 17:
					printf("Seventeen");
					break;

				case 18:
					printf("Eighteen");
					break;

				case 19:
					printf("Nineteen");
					break;
			} //switch (numArr[3] * 10 + numArr[4])
		} else {
			switch (numArr[3]) {
				case 2:
					printf("Twenty");
					break;

				case 3:
					printf("Thirty");
					break;

				case 4:
					printf("Fourty");
					break;

				case 5:
					printf("Fifty");
					break;

				case 6:
					printf("Sixty");
					break;

				case 7:
					printf("Seventy");
					break;

				case 8:
					printf("Eighty");
					break;

				case 9:
					printf("Ninety");
					break;
			} //switch (numArr[3])

			if(numArr[4]>0){
				printf("-");
			}

			printDigitWord(numArr[4]);
		} //End of extended if clause
	} //End of extended if clause
} //void numToWord(int num)