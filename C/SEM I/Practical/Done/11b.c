/* Write a C program to find largest of three numbers */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int num1, num2, num3;

		printf("Enter three numbers: ");
		scanf("%d%d%d", & num1, & num2, & num3);

		if (num1 > num2 && num1 > num3) {
			printf("The greatest number is: %d", num1);
		} else if (num2 > num1 && num2 > num3) {
			printf("The greatest number is: %d", num2);
		} else if (num3 > num1 && num3 > num2) {
			printf("The greatest number is: %d", num3);
		} else {
			printf("The numbers are equal");
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