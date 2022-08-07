/* Write a C program to check whether a number is even or odd */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int num;

		printf("Enter the number to check: ");
		scanf("%d", & num);

		if (num % 2 == 0) {
			printf("%d is even\n", num);
		} else if (num % 2 != 0) {
			printf("%d is odd\n", num);
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