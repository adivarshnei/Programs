/* 

Assignemnt III
Name: Adersh Varshnei
5. Write a C Program to find all prime factors of a number

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

void primeFactFind(int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputNum;

		printf("Enter the number whose prime factors are to be found (Positive Factors will be found for negative numbers): ");
		scanf("%d", & inputNum);

		primeFactFind(inputNum);

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

void primeFactFind(int num) {
	loopVar i = 2;
	int temp = num;

	printf("The prime factors of %d are:\n", num);

	do {
		if (abs(temp) % i == 0) {
			printf("%d\t", i);

			temp /= i;
			i = 2;
		} else {
			i++;
		} //End of extended if clause
	} while (i <= abs(temp));
} //void primeFactFind(int num)