/* 

Assignemnt IV
Name: Adersh Varshnei
3. Write a C Program to find sum of all-natural numbers between 1 to n using recursion

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************************************

typedef unsigned int loopVar;
typedef char bufferClear;

//************************************************************************************************

long int seriesSummation(long int);

//************************************************************************************************

int count = 0;
bufferClear temp;

//************************************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		long int inputNum;
		long int sum;

		do {
			printf("Enter the number upto which sum is to be taken: ");
			scanf("%ld", & inputNum);

			if (inputNum < 0) {
				printf("Invalid Entry. Please enter a natural number limit\n.");
			} //if (inputNum < 0)
		} while (inputNum < 0);

		sum = seriesSummation(inputNum);

		printf("Sum: %ld", sum);

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

long int seriesSummation(long int partSum) {
	if (partSum > 0) {
		return (partSum + seriesSummation(partSum - 1));
	} else {
		return 0;
	} //End of extended if clause
} //long int seriesSummation(long int partSum)