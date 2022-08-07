/* Write a C program to find smallest of two numbers */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int num1, num2;

		printf("Enter the two numbers: ");
		scanf("%d%d", & num1, & num2);

		if (num1 < num2) {
			printf("%d is lower than %d", num1, num2);
		} else if (num1 > num2) {
			printf("%d is lower than %d", num2, num1);
		} else {
			printf("%d and %d are equal", num1, num2);
		}

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