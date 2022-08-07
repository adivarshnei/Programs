/* 

Assignemnt III
Name: Adersh Varshnei
2. Write a C Program to find all factors of a number

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************

typedef unsigned int loopVar;

//************************************************************************************************

void factFind(int);

//************************************************************************************************

int count = 0;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		int inputNum;

		printf("Enter the number whose factors are to be found (Positive Factors will be found for negative numbers): ");
		scanf("%d", & inputNum);

		factFind(inputNum);

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

void factFind(int num) {
	loopVar i;
	int factCount = 0;
	printf("The factors of %d are:\n", num);

	for (i = 1; i <= abs(num); i++) {
		if (abs(num) % i == 0) {
			printf("%d\t", i);
			factCount++;
		} //if (abs(num) % i == 0)
	} //for (i = 1; i <= abs(num); i++)

	printf("\n%d has %d factors\n", num, factCount);
} //void factFind(int num)