/* Write a program to find the sum of the following series:
1/1! + 2/2! + 3/3! ... up to 7 terms */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float sum = 0, term, factTerm;
		int i, j;

		for (i = 1; i <= 7; i++) {
			factTerm = 1;

			for (j = 1; j <= i; j++) {
				factTerm *= j;
			}

			term = i / factTerm;

			sum += term;

			printf("%f", term);

			if (i != 7) {
				printf(" + ");

			}
		}

		printf("\n= %f", sum);

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