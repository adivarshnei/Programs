/* 

Assignemnt IV
Name: Adersh Varshnei
5. Write a C Program to find reverse of any number using recursion

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************************************

int numReverse(int);

//************************************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputNum, revNum;

		printf("Enter the number (Neagative numbers will be converted into positive): ");
		scanf("%d", & inputNum);

		revNum = numReverse(abs(inputNum));

		printf("Reverse of %d is %d", abs(inputNum), revNum);

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

int numReverse(int normNum) {
	int numLength;

	numLength = (int) log10(normNum);

	if (normNum != 0) {
		return (normNum % 10 * pow(10, numLength)) + numReverse((int) normNum / 10);
	} else {
		return 0;
	} //End of extended if clause
} //int numReverse(int normNum)