/* Write a C program to check whether a number is Prime, Armstrong or Perfect number using functions */

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

enum boolFlag primeChk(int, loopVar);
enum boolFlag armstChk(int);
enum boolFlag prfctChk(int);

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputNum;
		enum boolFlag primeFlag, armstFlag, prfctFlag;

		printf("Enter the number (Negative numbers will be converted to positive): ");
		scanf("%d", & inputNum);

		primeFlag = primeChk(abs(inputNum), 2);
		armstFlag = armstChk(abs(inputNum));
		prfctFlag = prfctChk(abs(inputNum));

		switch (primeFlag) {
			case TRUE:
				printf("%d is a prime number.\n", inputNum);

				break;

			case FALSE:
				printf("%d is not a prime number.\n", inputNum);

				break;
		} //switch (primeFlag)

		switch (armstFlag) {
			case TRUE:
				printf("%d is an Armstrong number.\n", inputNum);

				break;

			case FALSE:
				printf("%d is not an Armstrong number.\n", inputNum);

				break;
		} //switch (armstFlag)

		switch (prfctFlag) {
			case TRUE:
				printf("%d is a Perfect number.\n", inputNum);

				break;

			case FALSE:
				printf("%d is not a Perfect number.\n", inputNum);

				break;
		} //switch (prfctFlag)

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

enum boolFlag primeChk(int num, loopVar i) {
	if (num == 0 || num == 1) {
		return FALSE;
	} else if (num == 2) {
		return TRUE;
	} else if (num % i == 0) {
		return FALSE;
	} else if ((int) pow(i, 2) > num) {
		return TRUE;
	} //End of extended if clause

	return primeChk(num, i + 1);
} //enum boolFlag primeChk(int num, loopVar i)

//************************************************************************

enum boolFlag armstChk(int num) {
	loopVar i;
	int cubeSum = 0;

	for (i = num; i > 0; i /= 10) {
		cubeSum += round(pow(i % 10, 3));
	} //for (i = num; i > 0; i /= 10) 

	if (cubeSum == num) {
		return TRUE;
	} else {
		return FALSE;
	} //End of extended if clause
} //enum boolFlag armstChk(int num)

//************************************************************************

enum boolFlag prfctChk(int num) {
	loopVar i;
	int factSum = 0;

	for (i = 1; i < num; i++) {
		if (num % i == 0) {
			factSum += i;
		} //if (num % i == 0)
	} //for (i = 1; i < num; i++)

	if (factSum == num) {
		return TRUE;
	} else {
		return FALSE;
	} //End of extended if clause
} //enum boolFlag prfctChk(int num)