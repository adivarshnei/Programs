/* Write a C Program to add two numbers */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int var1, var2, sum;

		printf("Enter the two numbers: ");
		scanf("%d%d", & var1, & var2);

		sum = var1 + var2;

		printf("Sum of %d and %d is %d", var1, var2, sum);

		printf("\nRepeat Program?: ");
		scanf("%d", & rep);

		count++;

		if (count >= 50) {
			printf("Abnormal END\n");

			getch();
			exit(0);
		}

	}

	printf("Normal END\n");

	getch();
	return 0;
}