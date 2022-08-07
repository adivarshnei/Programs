/* 

Assignemnt IV
Name: Adersh Varshnei
1. Write a C Program to print all natural numbers between 1 to n using function

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************************************

void printNatNum(int);

//************************************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputLim;

		printf("Enter the limit upto which the natural numbers are to be printed (Neagative numbers will be converted into positive): ");
		scanf("%d", & inputLim);

		printNatNum(abs(inputLim));

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

void printNatNum(int lim) {
	loopVar i;

	printf("The natural numbers upto %d are: \n", lim);

	for (i = 1; i <= lim; i++) {
		printf("%d\t", i);
	} //for (i = 1; i <= lim; i++)
} //void printNatNum(int lim)