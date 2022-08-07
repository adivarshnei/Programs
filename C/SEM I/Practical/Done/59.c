/* Write a C Program to check whether a number is ever or odd using functions */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

enum boolType {
	ODD = 1,
	EVEN
}; //enum boolType

//************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************

enum boolType oddEvenChk(int);

//************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputNum;
		enum boolType type;

		printf("Enter the number (Negative numbers will be converted to positive): ");
		scanf("%d", & inputNum);

		type = oddEvenChk(abs(inputNum));

		switch (type) {
			case EVEN:
				printf("%d is an even number.", abs(inputNum));

				break;

			case ODD:
				printf("%d is an odd number.", abs(inputNum));

				break;
		} //switch (type)

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

enum boolType oddEvenChk(int num) {
	if (num % 2 == 0) {
		return EVEN;
	} else {
		return ODD;
	} //End of extended if clause
} //enum boolType oddEvenChk(int num)