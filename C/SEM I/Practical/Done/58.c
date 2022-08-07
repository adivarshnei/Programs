/* Write a C Program to calcuate the factorial of a number using recursion */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//************************************************************************

typedef int loopVar;

//************************************************************************

long int factorial(long int);

//************************************************************************

int count = 0;

//************************************************************************

int main(void) {
	loopVar rep = 1;

	while (rep == 1) {
		long int num, fact;
		int i;

		printf("Enter the number to find the factorial of: ");
		scanf("%ld", & num);

		if (num < 0) {
			printf("Factorial of negative numbers is undefined\n");
		} else {
			fact = factorial(num);

			printf("%ld! = %ld\n", num, fact);
		} //End of extended if clause

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

long int factorial(long int num) {
	if (num >= 1) {
		return num * factorial(num - 1);
	} else {
		return 1;
	} //End of extended if clause
} //long int factorial(long int num)