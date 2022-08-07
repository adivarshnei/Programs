/* 

Assignemnt IV
Name: Adersh Varshnei
6. Write a C Program to check whether a number is palindrome or not using recursion

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

enum boolFlag {
	FALSE = 1,
	TRUE
}; //enum boolFlag

//************************************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************************************

enum boolFlag palinChk(int);
int numReverse(int);

//************************************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputNum;
		enum boolFlag flag;

		printf("Enter the number (Neagative numbers will be converted into positive): ");
		scanf("%d", & inputNum);

		flag = palinChk(abs(inputNum));

		switch (flag) {
			case TRUE:
				printf("%d is a palindrome number.\n", abs(inputNum));
				break;

			case FALSE:
				printf("%d is not a palindrome number.\n", abs(inputNum));
				break;
		} //switch (flag)

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

enum boolFlag palinChk(int normNum) {
	if (normNum == numReverse(normNum)) {
		return TRUE;
	} else {
		return FALSE;
	} //End of extended if clause
} //enum boolFlag palinChk(int normNum)

//************************************************************************************************

int numReverse(int normNum) {
	int numLength;

	numLength = (int) log10(normNum);

	if (normNum != 0) {
		return (normNum % 10 * pow(10, numLength)) + numReverse((int) normNum / 10);
	} else {
		return 0;
	} //End of extended if clause
} //int numReverse(int normNum)