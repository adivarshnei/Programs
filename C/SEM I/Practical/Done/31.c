/* Write a program to find the sum of the following series:
1^4 + 3^4 + 5^4 + 7^4 ... up to 100 terms */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		float sum = 0, term;
		int i;

		for (i = 1; i <= 100; i++) {
			term = pow((2 * i - 1), 4.0);
			sum += term;

			printf("%.0f", term);

			if (i != 100) {
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