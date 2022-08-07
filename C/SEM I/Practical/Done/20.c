/* Write a program in C to accept an integer from the user and to find the sum of its digits */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int num, sum = 0, i;

		printf("Enter the number: ");
		scanf("%d", & num);

		for (i = num; i > 0; i /= 10) {
			sum += i % 10;

			if (i / 10 > 0) {
				printf("%d + ", i % 10);
			} else {
				printf("%d", i % 10);
			}
		}

		printf(" = %d", sum);

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