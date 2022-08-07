/* Write a program to print Fibonacci sequence 0 1 1 2 3 5 8 13... up to N terms or up to a certain value and print the sum of sequence*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		long int n, sum = 0, lim;
		long int num1 = 0, num2 = 1, numNext = 0;
		int choice, i;

		do {
			printf("1. Number of Terms\n");
			printf("2. Up to certain value\n");
			printf("Enter the choice: ");
			scanf("%d", & choice);

			switch (choice) {
				case 1:
					printf("Enter the number of terms in the sequence (Negative values will be converted into their additive inverse): ");
					scanf("%ld", & n);

					for (i = 0; i < abs(n); i++) {
						numNext = num1 + num2;
						sum += num1;

						printf("%ld\t", num1);

						num1 = num2;
						num2 = numNext;
					}

					printf("\nSum of %ld terms = %ld", abs(n), sum);

					break;

				case 2:
					printf("Enter the limit of values in the sequence (Negative values will be converted into their additive inverse): ");
					scanf("%ld", & lim);

					for (i = 0; num1 <= abs(lim); i++) {
						numNext = num1 + num2;
						sum += num1;

						printf("%ld\t", num1);

						num1 = num2;
						num2 = numNext;
					}

					printf("\nSum of terms up to %ld = %ld", abs(lim), sum);

					break;

				default:
					printf("Wrong Option\n");
					break;
			}
		} while (choice != 1 && choice != 2);

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