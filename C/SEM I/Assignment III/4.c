/* 

Assignemnt III
Name: Adersh Varshnei
4. Write a C Program to find LCM of two numbers

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

void lcmDef(int, int, int * );

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputFirstNum, inputSecondNum;
		int LCM;

		printf("Enter the two numbers of which the LCM is to be found (Negative nummbers will be considered as positive): ");
		scanf("%d%d", & inputFirstNum, & inputSecondNum);

		lcmDef(abs(inputFirstNum), abs(inputSecondNum), & LCM);

		printf("Lowest Common Multiple of %d and %d is: %d", abs(inputFirstNum), abs(inputSecondNum), LCM);

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

void lcmDef(int firstNum, int secondNum, int * LCM) {
	loopVar i = 1;

	while (1) {
		if (i % firstNum == 0 && i % secondNum == 0) {
			* LCM = i;

			return;
		}

		i++;
	}
}