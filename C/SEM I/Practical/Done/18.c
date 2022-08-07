/* Write a program to find the factorial of any number */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		long int num, fact = 1;
		int i;

		printf("Enter the number to find the factorial of: ");
		scanf("%ld", & num);

		if (num < 0) {
			printf("Factorial of negative numbers in undefined\n");
		} else if (num == 0) {
			printf("0! = 1\n");
		} else {
			for (i = num; i > 0; i--) {
				fact *= i;
			}

			printf("%ld! = %ld\n", num, fact);
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