/* Write a program to find the sum of the following series:
S = 1^4 + 3^4 + 5^4 + 7^4 + ... 100 terms */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		double currTerm = 1;
		double sum = 0.00;
		int i;

		for (i = 0; i < 100; i++, currTerm += 2) {
			sum = sum + pow(currTerm, 4);

			if (i < 99) {
				printf("%0.f^4 + ", currTerm);
			} else {
				printf("%0.f^4", currTerm);
			}
		}

		printf("\n = %E", sum);

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