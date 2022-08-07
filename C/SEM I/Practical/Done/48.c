/* Write a program to find product, sum, average, maximum and minimum from a list of n numbers */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int intArr;

int count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		intArr a[50];
		int n;
		long int prod = 1, sum = 0, max, min;
		float avg = 0;
		int i;

		printf("Enter the number of terms to be compared: ");
		scanf("%d", & n);

		for (i = 0; i < n; i++) {
			printf("Enter term %d: ", (i + 1));
			scanf("%d", & a[i]);
		}

		max = a[0];
		min = a[0];

		for (i = 0; i < n; i++) {
			sum += a[i];
			prod *= a[i];
			avg += a[i];

			if (a[i] > max) {
				max = a[i];
			}

			if (a[i] < min) {
				min = a[i];
			}
		}

		avg /= n;

		printf("\nSum: %ld", sum);
		printf("\nProduct: %ld", prod);
		printf("\nAverage: %.2f", avg);
		printf("\nMaximum: %ld", max);
		printf("\nMinimum: %ld", min);

		printf("\n\nRepeat Program?: ");
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