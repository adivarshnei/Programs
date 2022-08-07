/* Write a program to find the sum of the following series:
S = 2 + 4 + 6 + 8 + ... N terms */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		int terms, currTerm = 2, i;
		long int sum = 0;

		printf("Enter the number of terms in the series: ");
		scanf("%d", & terms);

		for (currTerm = 2, i = terms; i > 0; currTerm += 2, i--) {
			sum += currTerm;

			if (i > 1) {
				printf("%d + ", currTerm);
			} else {
				printf("%d", currTerm);
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