/* 

Assignemnt IV
Name: Adersh Varshnei
8. Write a C Program to generate nth Fibonacci term using recursion

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************************************

int fibGen(int);

//************************************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputLim, genFibNum;

		printf("Enter the index of the term to be generated (Negative numbers will be considered to be positive): ");
		scanf("%d", & inputLim);

		genFibNum = fibGen(abs(inputLim));

		printf("Fibonacci Number %d is %d", abs(inputLim), genFibNum);

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

int fibGen(int lim) {
	if (lim != 0 && lim != 1) {
		return fibGen(lim - 1) + fibGen(lim - 2);
	} else {
		return lim;
	}//End of extended if clause
}//int fibGen(int lim)