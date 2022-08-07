/* 

Assignemnt III
Name: Adersh Varshnei
1. Write a C Program to find power of a number using for loop

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

void powFunc(int, unsigned int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputNum;
		unsigned int inputPow;

		printf("Enter the base: ");
		scanf("%d", & inputNum);

		printf("Enter the power: ");
		scanf("%u", & inputPow);

		powFunc(inputNum, inputPow);

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

void powFunc(int num, unsigned int power) {
	loopVar i = 0;
	long int powNum = 1;

	for (i = 0; i < power; i++) {
		powNum *= num;
	} //for (i = 0; i < power; i++)

	printf("%d ^ %u = %ld\n", num, power, powNum);
} //void powFunc(int num, unsigned int power)