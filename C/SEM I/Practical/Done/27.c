/* Write a program to find the sum of the following series:
1! + 2! + 3! + 4! + 5! ... up to n terms */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float sum = 0, term;
		int n;
		int i, j;

		printf("Enter the number of terms upto which sum is to be calculated: ");
		scanf("%d", & n);

		for (i = 1; i <= n; i++) {
			term = 1;

			for (j = 1; j <= i; j++) {
				term *= j;
			}

			sum += term;

			printf("%.0f", term);

			if (i != n) {
				printf(" + ");
			}
		}

		printf("\n= %.0f", sum);

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