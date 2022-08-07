/* Write a C Program to calcuate the factorial of a number using function */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************

typedef int loopVar;

//************************************************************************

void factorial(long int);

//************************************************************************

int count = 0;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		long int num;
		int i;

		printf("Enter the number to find the factorial of: ");
		scanf("%ld", & num);

		factorial(num);

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);

		count++;

		if (count >= 50) {
			printf("Abnormal END\n");

			getch();
			exit(0);
		} //if (count >= 50)

	} //while (rep == 1)

	printf("Normal END\n");

	getch();
	return 0;
} //int main(void)

//************************************************************************

void factorial(long int num) {
	long int fact = 1;
	loopVar i;

	if (num < 0) {
		printf("Factorial of negative numbers in undefined\n");
	} else if (num == 0) {
		printf("0! = 1\n");
	} else {
		for (i = num; i > 0; i--) {
			fact *= i;
		} //for (i = num; i > 0; i--)

		printf("%ld! = %ld\n", num, fact);
	} //End of extended if clause
} //void factorial(long int num)